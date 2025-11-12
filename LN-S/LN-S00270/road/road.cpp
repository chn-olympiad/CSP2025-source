#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    vector<int>u(m+1);
    vector<int>v(m+1);
    vector<int>w(m+1);
    int a[k+1][n+1];
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }
    for(int i=1;i<=k;i++){
        int c[k+1];
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(k<=0)for(int i=1;i<=m;i++)sum+=w[i];
    printf("%d",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
