#include<bits/stdc++.h>
using namespace std;
int a[30],n;
int ans=0;
void doit(int x){
    int ma=0,sum=0,siz=0;
    for(int i=0;i<n;i++){
        if((x>>i)&1){
           sum+=a[i];
           ma=max(ma,a[i]);
           ++siz;
        }
    }
    if(siz<3)return;
    if(sum>2*ma)++ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<(1<<n);i++){
            doit(i);
    }
    cout<<ans;
return 0;
}
