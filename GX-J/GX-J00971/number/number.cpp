#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    vector<int> dight;
    for(auto c:str){
        if(isdigit(c)) dight.push_back(c-48);
    }
    sort(dight.begin(),dight.end(),cmp);
    for(auto d:dight) cout<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
