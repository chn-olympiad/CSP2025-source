#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn;
int ans,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2) return 0;
    if(n==3){
        maxn=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>maxn*2){
            cout<<1;
            return 0;
        }else{
            return 0;
        }
    }
    for(int x=1;x<=n-2;x++){
        sum=0;
        maxn=0;
        for(int y=x;y<=n-1;y++){
            for(int z=y;z<=n;z++){
                sum=0;
                if(a[x]>maxn) maxn=a[x];
                if(a[y]>maxn) maxn=a[y];
                if(a[z]>maxn) maxn=a[z];
                sum+=a[x]+a[y]+a[z];
            } 
            if(sum>maxn*2){
                ans++;
            }
        }
       
    }
    cout<<ans;
    return 0;
}