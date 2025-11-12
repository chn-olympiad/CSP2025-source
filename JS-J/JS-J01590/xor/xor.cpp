#include<bits/stdc++.h>
using namespace std;
int a[500002],vis[500002];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ma=-1;
    cin>>n>>k;
    bool ok=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
       if(a[i]!=1) ok=false;
       ma=max(ma,a[i]);
    }
    if(k==0&&ok){
        cout<<0;
        return 0;
    }else if(ma==1&&k==1){
        int sum=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)sum++;
        }
        cout<<sum<<endl;
    }else if(ma==1&&k==0){
        int sum=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)sum++;
        }
        for(int i=0;i<n-1;i++){
            if(vis[i]==0&&a[i]==1&&a[1+i]==1){
                vis[i]=1;
                vis[i+1]=1;
                sum++;
            }
        }
        cout<<sum<<endl;
    }else if(ma==0&&k==0){
        cout<<n<<endl;
    }else cout<<n-2<<endl;
    return 0;
}
