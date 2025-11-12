#include<bits/stdc++.h>
using namespace std;
int n,m,k,o,r1,r2;
struct node {
	int x,y,z;
} a[1000010],d[1000010];
int c[20][10010],b[20],f[100010],h[20],p,cnt,l;
long long num,sum;
bool cmp(node s1,node s2) {
	return s1.z<s2.z;
}
int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void dfs(int q)
{
	if(q==k)
	{
		sum=0;
		cnt=p;
		for(int i=1;i<=cnt;i++) a[i].x=d[i].x,a[i].y=d[i].y,a[i].z=d[i].z;
		for(int i=1;i<=q;i++)
		{
			if(h[i]==1)
			{
				sum+=b[i];
				for(int j=1; j<=n; j++) a[++cnt].x=n+i,a[cnt].y=j,a[cnt].z=c[i][j];
				l++;
			}
		}
		if(l==0) return ;
		sort(a+1,a+1+cnt,cmp);
		for(int i=1; i<=n+l; i++) f[i]=i;
		o=0;
		for(int i=1; i<=cnt; i++) {
			if(o==n+l-1) break;
			r1=find(a[i].x),r2=find(a[i].y);
			if(r1!=r2) {
				f[r1]=r2;
				sum+=a[i].z;
				o++;
			}
		}
		if(sum<num) num=sum;
		return ;
	}
	h[q+1]=1;
	dfs(q+1);
	h[q+1]=2;
	dfs(q+1);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+m+1,cmp);
	for(int i=1; i<=k; i++) {
		cin>>b[i];
		for(int j=1; j<=n; j++) cin>>c[i][j];
	}
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=1; i<=m; i++) {
		if(p==n-1) break;
		r1=find(a[i].x),r2=find(a[i].y);
		if(r1!=r2) {
			f[r1]=r2;
			num+=a[i].z;
			p++;
			d[p].x=a[i].x,d[p].y=a[i].y,d[p].z=a[i].z;
		}
	}
	dfs(0);
	cout<<num;
	return 0;
}
