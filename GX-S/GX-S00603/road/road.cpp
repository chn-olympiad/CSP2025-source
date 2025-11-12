#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],cc[15][50005],f[50005],n2,m2;
struct node{
	long long u,v,w;
}a[2000005];
int find(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	n2=n;
	m2=m;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		n2++;
		for(int j=1;j<=n;j++){
			cin>>cc[i][j];
			a[++m2].u=n2,a[m2].v=j,a[m2].w=cc[i][j];
		}
	}
	/*n2++;
	for(int i=1;i<=k;i++){
		a[++m2].u=n2,a[m2].v=n+i,a[m2].w=0;
	}*/
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		sort(a+1,a+m+1,cmp);
		long long sum=0;
		for(int i=1;i<=m;i++){
			int x=a[i].u,y=a[i].v;
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				sum+=a[i].w;
				f[fy]=fx;
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n2;i++){
		f[i]=i;
	}
	sort(a+1,a+m2+1,cmp);
	long long sum=0;
	for(int i=1;i<=m2;i++){
		int x=a[i].u,y=a[i].v;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			sum+=a[i].w;
			f[fy]=fx;
		}
	}
	cout<<sum;
	return 0;
}
/*4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4


 */
