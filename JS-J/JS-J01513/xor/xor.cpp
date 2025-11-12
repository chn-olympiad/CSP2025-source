#include<bits/stdc++.h>
using namespace std;
long long n,k,x,y,ans=0,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)x++;
        else if(a[i]==0)y++;
    }
    if(x==n&&k==0){
        cout<<x/2;
        return 0;
    }
    else if(x+y==n&&k==0){
        for(int i=1;i<=n;i++){
            while(a[i]==1&&a[i+1]==1)ans++,i+=2;
        }
        cout<<ans+y;
    }
    else if(x+y==n&&k==1){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1])ans++,i++,x--;
        }
        cout<<ans+x;
    }
    return 0;
}
