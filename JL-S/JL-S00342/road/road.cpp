#include<bits/stdc++.h>
using namespace std;
struct bb{
    int a,b,w;
}a[1000001];
int fa[100000];long long n,m,k;
int finda(int i){
if(fa[i]==i)
    return i;
return finda(fa[i]);
}
bool cmp(bb a,bb b){
return a.w<b.w;
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);

cin>>n>>m>>k;
for(long long i=1;i<=n;i++){
    fa[i]=i;
}
for(long long i=1;i<=m;i++){
    cin>>a[i].a>>a[i].b>>a[i].w;
}
bool aa=0;
for(long long i=1;i<=k;i++){
    int y;
    cin>>y;
    if(y!=0){
        aa=1;
        break;
    }
}
if(aa==0&&k!=0){
    cout<<"0";
    return 0;
}
sort(a+1,a+m+1,cmp);
long long ans=0;
for(long long i=1;i<=m;i++){
    if(finda(a[i].a)!=finda(a[i].b)){
        ans+=a[i].w;
        fa[finda(a[i].a)]=a[i].b;
    }
}
cout<<ans;
}
