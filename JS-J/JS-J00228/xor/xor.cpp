#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],b[30],ans,maxn;
int fx(int x,int y){
    int l=1,num=0;
    while(max(x,y)>0){
        if(x%2!=y%2) b[l]=1;
        else b[l]=0;
        x/=2,y/=2;
        l++;
    }
    for(int i=1;i<l;i++){
        num+=b[i]*pow(2,i-1);
    }
    return num;
}
signed main(){
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans=a[i];
            for(int k=i+1;k<=j;k++){
                ans=fx(ans,a[k]);
            }
            if(ans==k) maxn++;
        }
    }
    cout<<maxn;
    return 0;
}
