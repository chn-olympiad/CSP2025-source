#include<iostream>
using namespace std;
int a[1000],c[1000],u[1000],v[1000],w[100000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i];
        }
    }
    if(n<=1000&&n<=100000&&k<=5){
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;i++){
                if(w[j]<=w[i]){
                    swap(w[i],w[j]);
                }
            }
        }
        for(int i=1;i<n;i++){
            ans+=w[i];
        }
        cout<<ans;
    }
    else if(n<=1000&&n<=1000000&&k<=5){
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;i++){
                if(w[j]<=w[i]){
                    swap(w[i],w[j]);
                }
            }
        }
        for(int i=1;i<n;i++){
            ans+=w[i];
        }
        cout<<ans;
    }
    else if(n<=1000&&n<=1000000&&k<=10){
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;i++){
                if(w[j]<=w[i]){
                    swap(w[i],w[j]);
                }
            }
        }
        for(int i=1;i<n;i++){
            ans+=w[i];
        }
        cout<<ans;
    }
    else if(n<=10000&&n<=1000000&&k<=5){
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;i++){
                if(w[j]<=w[i]){
                    swap(w[i],w[j]);
                }
            }
        }
        for(int i=1;i<n;i++){
            ans+=w[i];
        }
        cout<<ans;
    }

    return 0;
}
