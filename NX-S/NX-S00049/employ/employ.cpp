#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
struct inter{
    bool f=false;
    int x;
}a[505];
int n,m;
long long num;
int k[505];
string s;
void dfs(int day,int peo,int pas){
    if(day>n){
        if(peo>=m) num=(num+1)%988244353;
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i].f) continue;
        a[i].f=true;
        if(k[day]&&a[i].x>pas){
            dfs(day+1,peo+1,pas);
        }
        else dfs(day+1,peo,pas+1);
        a[i].f=false;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=0;i<s.length();i++) k[i+1]=s[i]-'0';
    dfs(1,0,0);
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
