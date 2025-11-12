#include<bits/stdc++.h>
using namespace std;
int n,k,a[500007],last=0,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i=-~i){
        cin>>a[i];
        for(int j=last+1;j<=i;j=-~j){
            int s=0;
            for(int t=j;t<=i;t=-~t){s^=a[t];}
            if(s==k){ans++,last=i;break;}
        }
    }
    cout<<ans;
    return 0;
}
