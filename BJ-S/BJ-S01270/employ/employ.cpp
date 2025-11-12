#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[505];
int a[505];
int x[15];
int t=1;
bool check(){
    int now=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[x[i]]<=now){
            now++;
            continue;
        }
        if(c[i]=='0')now++;
        else ans++;
    }
    if(ans>=m)return 1;
    else return 0;
}
int ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>c+1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        x[i]=i;
    }
    for(int i=1;i<=n;i++)t*=i;
    for(int i=1;i<=t;i++){
        ans+=check();
    //   for(int i=1;i<=n;i++)cout<<x[i]<<" ";
      //  cout<<endl;
        next_permutation(x+1,x+n+1);
    }
  //  cout<<t<<endl;
    cout<<ans;
}
