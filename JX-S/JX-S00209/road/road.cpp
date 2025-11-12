#include<bits/stdc++.h>
using namespace std;
int fi[10005];
struct road{
    int u,v,w;
}a[1000005];
int n,m,k,ans=0;
bool cmp(road a,road b){
    return a.w<b.w;
}
int fin(int x){
    if(fi[x]==x)return x;
    else return fi[x]=fin(fi[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fi[i]=i;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        int x=a[i].u,y=a[i].v;
        x=fin(x);y=fin(y);
        //cout<<x<<" "<<y<<endl;
        if(x==y)continue;
        ans+=a[i].w;
        fi[x]=y;
    }
   // for(int i=1;i<=n;i++)cout<<fi[i]<<endl;
    cout<<ans;
    return 0;
}
/*6 7 0
1 5 1
1 3 3
1 4 3
2 3 2
2 4 4
4 5 5
5 6 2
*/
