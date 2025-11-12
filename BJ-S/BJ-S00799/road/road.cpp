#include <bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int a[100005],b[100005],c[100005];
int d[100005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int sum=0;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        sum+=c[i];
        d[a[i]]++;
        d[b[i]]++;
    }
    for(int i=1;i<=m;i++){
        if(d[a[i]==1]||d[b[i]]==1) c[i]==0;
    }
    sort(c+1,c+1+m,cmp);
    int x=(m-n+1);
    for(int i=1;i<=x;i++) sum-=c[i];
    cout<<sum;
    return 0;
}