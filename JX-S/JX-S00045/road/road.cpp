#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans=0;
int a1[1000005],a2[1000005],a3[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int t;
    cin>>n>>m>>k;
    for(int j=1;j<=m;j++){
        cin>>a1[j]>>a2[j]>>a3[j];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>a[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        if(a1[j]<a2[j]&&a1[j]<a3[j])ans+=a1[j];
        else if(a2[j]<a1[j]&&a2[j]<a3[j])ans+=a2[j];
        else if(a3[j]<a2[j]&&a3[j]<a1[j])ans+=a3[j];
    }
    cout<<ans<<endl;

    return 0;
}

