#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int v[10000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t=0;
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        if(c>t)
            for(int j=0;j<n;j++) cin>>v[j];
    }
    sort(a,a+n);
    sort(v,v+n);
    int ans=0;
    for(int i=0;i<n/2;i++) ans+=a[i];
    for(int i=0;i<n/2;i++) ans+=v[i];
    cout<<ans;
    return 0;
}
