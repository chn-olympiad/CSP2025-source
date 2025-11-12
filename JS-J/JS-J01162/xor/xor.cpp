#include<bits/stdc++.h>
using namespace std;
long long n,k,p=0,q=0;
long long a[500005];
long long vis[500005];
bool x=0,y=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    vis[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=vis[i-1]^a[i];
        if(a[i]!=1){
            x=1;
            if(a[i]!=0){y=1;}
        }
        if(a[i]==1){p++;}
        if(a[i]==0){q++;}
    }
    if(k==1&&!x){cout<<n<<endl;return 0;}
    if(k==1&&x&&!y){cout<<p<<endl;return 0;}
    if(k==0&&!x){cout<<n/2<<endl;return 0;}
    if(k==0&&x&&!y){cout<<q<<endl;return 0;}
    int ans=0,num;
    for(int i=1;i<=n;i++){
        num=0;
        for(int j=i;j<=n;j++)
            for(int l=j;l<=n;l++)
                if((vis[l]^vis[j-1])==k){
                    num++;j=l+1;break;}
        ans=max(num,ans);
    }
    cout<<ans<<endl;
    return 0;
}
