#include <bits/stdc++.h>
using namespace std;
long long n,m,k,f[10005],ans,t;
struct node{
	long long a,b,c;	
}a[1000001];
long long find(long long x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}bool cmp(node a,node b){
	return a.c<b.c;
}
void K(){
	for(long long i=1;i<=m;i++){
		long long x=find(a[i].a),y=find(a[i].b);
		if(x==y)continue;
		ans+=a[i].c;
		f[x]=y;
		t++;
		if(t==n-1)return;
	}
}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road2.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)f[i]=i;
	for(long long i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}sort(a+1,a+1+m,cmp);
	
	K();
	cout<<ans;
	return 0;
}