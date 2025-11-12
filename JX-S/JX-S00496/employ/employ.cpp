#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[20];
map<int,int>stt;
int ans;
void doit(int u,map<int,int>st,int cnt){
    if(cnt>m)return ;
    if(u==n+1){
        ++ans;
        return ;
    }

    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=1;
            if(s[i]=='1'||cnt>=a[i])++cnt;
            doit(u+1,st,cnt);
            if(s[i]=='1'||cnt>=a[i])--cnt;
            st[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
      ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;




    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    doit(1,stt,0);
    cout<<ans;

    return 0;
}
