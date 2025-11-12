#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
bool cmd(char a,char b){return a>b;}
char n[1000005];
vector<char>ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<strlen(n);i++){
        if(n[i]>='0'&n[i]<='9')ans.push_back(n[i]);
    }sort(ans.begin(),ans.end(),cmd);
    for(auto i:ans)cout<<i;
    return 0;
}
