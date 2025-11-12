#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int zhao(int r,int e){
    int x=e,y=a[r],u=n;
    for(int i=r;i<n;i++){
        if(y!=k&&i!=r) y=y^a[i];
        if(y==k){
            x+=1;
            u=i+1;
            //cout<<r<<' '<<i<<' '<<x<<endl;
            break;
        }
    }
    //cout<<"u="<<u<<endl;
    int p=x;
    for(int i=u;i<n;i++){
        x=max(x,zhao(i,p));
    }
    //cout<<"x="<<x<<endl;
    return x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<n;j++){
        ans=max(ans,zhao(j,0));
    }
    cout<<ans;
    return 0;
}
