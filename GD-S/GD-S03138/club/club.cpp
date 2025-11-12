#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+3;
int T,n,x,y,z,m,t[5],v[N],c[N];
ll s;
struct node{
	int a,b,c;
}a[N],b[N];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		m=s=t[1]=t[2]=t[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			v[i]=0;
			b[++m]={a[i].a,i,1};
			b[++m]={a[i].b,i,2};
			b[++m]={a[i].c,i,3};
		}
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(v[b[i].b])continue;
			v[b[i].b]=b[i].c,s+=b[i].a,t[b[i].c]++;
		}
		if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2){
			cout<<s<<'\n';
			continue;
		}
		m=0;
		if(t[1]>n/2)for(int i=1;i<=n;i++)if(v[i]==1)c[++m]=max(a[i].b,a[i].c)-a[i].a;
		if(t[2]>n/2)for(int i=1;i<=n;i++)if(v[i]==2)c[++m]=max(a[i].a,a[i].c)-a[i].b;
		if(t[3]>n/2)for(int i=1;i<=n;i++)if(v[i]==3)c[++m]=max(a[i].a,a[i].b)-a[i].c;
		sort(c+1,c+m+1,greater<int>());
		for(int i=1;i<=m-n/2;i++)s+=c[i];
		cout<<s<<'\n';
	}
}
