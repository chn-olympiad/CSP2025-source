// Failed
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n = 0;vector<vector<int>> member;
int satisfaction[3] = {0,0,0};
int population[3] = {0,0,0};
int maxInThree(int a,int b,int c){
    int rnum = (a>b?0:1);
    int ab = (rnum?b:a);
    return (c>ab?2:rnum);}
void solve(int nowPos,int posMax){
    if(nowPos>posMax){return;}
    vector<int> person = member[nowPos];
    // 计算加入优先级别
    int results[3] = {0,1,2};
    int result = maxInThree(person[0],person[1],person[2]);
    switch (result){
    case 0:
        results[0] = 0;
        if(person[1]>person[2]){results[1]=1;results[2]=2;}
        else{results[1]=2;results[2]=1;}break;
    case 1:
        results[0] = 1;
        if(person[0]>person[2]){results[1]=0;results[2]=2;}
        else{results[1]=2;results[2]=0;}break;
    case 2:
        results[0] = 2;
        if(person[0]>person[1]){results[1]=0;results[2]=1;}
        else{results[1]=1;results[2]=0;}break;}
    bool oped = false;
    for(auto x:results){
        // 累加
        satisfaction[x] += person[x];
        population[x]++;oped = true;
        // 回溯
        if(population[x]>(n/2)){
            population[x]--;oped = false;
            satisfaction[x] -= person[x];
        }
    }if(not oped){ // 失败后的结果
        satisfaction[results[2]] += person[results[2]];
        population[results[2]]++;oped = true;
    }solve(nowPos+1,posMax);
}
int main(){
    freopen("./club.in","r+",stdin);
    freopen("./club.out","w+",stdout);
    int t = 0;cin>>t;
    try
    {
        for(;t;t--){
        cin>>n;
        int tmp;vector<int> person;
        for(int i=n;i;i--){// input
            for(int i = 3;i;i--){cin>>tmp;person.push_back(tmp);}
            member.push_back(person);
            person.erase(person.begin(),person.end());
        }
        solve(0,n);
        cout<<satisfaction[0]+satisfaction[1]+satisfaction[2]<<endl;}

    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        cout<<n<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);return 0;
}
