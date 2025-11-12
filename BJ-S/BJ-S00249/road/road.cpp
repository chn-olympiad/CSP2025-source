#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1e6+5;
int n,m,k,a[N],ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y>>a[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            int s;
            cin>>x;
        }
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=n-1;i++){
        ans+=a[i];
    }
    cout<<ans;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
