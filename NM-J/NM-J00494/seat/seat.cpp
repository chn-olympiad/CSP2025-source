// lms Done at 1761967607.9599686
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility> // pair<>
#include <algorithm> // sort()
using namespace std;
int n,m; // 考场面积
int mySelf = 0; // 小R 的分数
vector<int> scores;
bool cmp(char a,char b){return a>b;}
int findMySelf(int me){
    for(int i = 0;i<scores.size();i++){
        if (scores[i]==me){return i+1;}}
    return -1;}
pair<int,int> getLocation2(int location1){
    int column = location1/n;
    int line = location1%n; // 行 列
    if(line == 0){line=n;}
    else{column++;}
    bool mode = (column%2); // 1👇，0☝
    if(not(mode)){line = n-line+1;} // 换算为实际位置
    pair<int,int> location2 = {column,line};
    return location2;
}; 
int main(){
    freopen("./seat.in","r+",stdin);
    freopen("./seat.out","w+",stdout);
    cin>>n>>m; int tmp;
    cin>>mySelf; scores.push_back(mySelf); // 小R单独处理
    for(int i = (n*m)-1;i;i--){cin>>tmp;scores.push_back(tmp);}
    sort(scores.begin(),scores.end(),cmp);
    pair<int,int> loc2 = getLocation2(findMySelf(mySelf));
    cout<<loc2.first<<' '<<loc2.second<<endl;
    fclose(stdin);
    fclose(stdout);return 0;
}