#include<bits/stdc++.h>
using namespace std;long long c[20],b[20][1000010],d[1000010];
struct ab{
	int u,v,w;
}a[2000010];
bool cmp(ab x,ab y){
	return x.w<y.w;
}
int find(int x){
	if(d[x]==x)return x;
	return find(d[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,z=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){cin>>c[i];if(c[i]!=0)z=1;
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			if(b[i][j]!=0)z=1;
		}
	}
	if(z==0){
		cout<<0;
		return 0;
	}
	if(k==0){
	for(int i=1;i<=n;i++){
		d[i]=i;
	}
		sort(a+1,a+m+1,cmp);long long ans=0;
		for(int i=1;i<=m;i++){
			int u1=a[i].u,v1=a[i].v,w1=a[i].w;
			u1=find(u1);
			v1=find(v1);
			if(u1!=v1){
				d[u1]=v1;
				ans+=w1;
			}
		}cout<<ans;
		return 0;
	}
	long long ans1=1000000000000000000;int m1;
	for(int i=0;i<1<<k;i++){
		m1=m;long long ans=0;
		ans=0;long long aa=1000000000000000;
		for(int j=1;j<=n;j++){
			for(int ac=j+1;ac<=n;ac++){aa=100000000000000;cout<<a;
				for(int ad=0;ad<k;ad++){
					if(1<<ad&i){
						aa=min(b[ad+1][j]+b[ad+1][ac],aa);
					}
				}
				m1++;
				a[m1].u=j;a[m1].v=ac;a[m1].w=aa;
			}
		}
		for(int j=1;j<=k;j++){
			if(1<<(j-1)&i)
			ans+=c[j];
		}
		for(int i=1;i<=n;i++){
		d[i]=i;
	}
		sort(a+1,a+m1+1,cmp);
		for(int i=1;i<=m1;i++){
			int u1=a[i].u,v1=a[i].v,w1=a[i].w;
			u1=find(u1);
			v1=find(v1);
			if(u1!=v1){
				d[u1]=v1;
				ans+=w1;
			}
		}ans1=min(ans,ans1);
	}cout<<ans1;
	return 0;
}