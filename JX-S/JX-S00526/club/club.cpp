#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        int x[100005],y[100005],z[100005];
        cin>>n;
        int maxn[100005],t=n/2,X,Y,Z;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i]>>z[i];
            maxn[i]=max(max(x[i],y[i]),z[i]);
            if(maxn[i]==x[i])
                X++;
            else if(maxn[i]==y[i])
                Y++;
            else
                Z++;
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=maxn[i];
        }
        int minn=1e9;
        if(X<=t&&Y<=t&&Z<=t){
            cout<<sum<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;i++){
                    minn=min(minn,x[i]-y[j]);
                }
            }
            cout<<sum-minn<<endl;
        }
    }
    return 0;
}
