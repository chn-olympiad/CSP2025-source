#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct bian{
	int node1,node2,v;
}b[1050005];
int s;
int a[1000005];
bool cmp(bian x,bian y){
	return x.v<y.v;
}
int find(int x){
	if(a[x]==x) return x;
	a[x]=find(a[x]);
	return a[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].node1>>b[i].node2>>b[i].v;	
	}
	int sm=m,sn=n,sum,minn=1e15+5;
	
	int nas=0;
	for(int i=1;i<=n;i++) a[i]=i;
	sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(find(a[b[i].node1])!=find(a[b[i].node2]))
				a[find(a[b[i].node1])]=a[find(a[b[i].node2])],
				nas+=b[i].v;
		}
	minn=min(minn,nas);
	
	for(int i=1;i<=k;i++){
		int ans=0;
		m=sm;
		n=sn+1;
		for(int i=1;i<=n;i++) a[i]=i;
		cin>>sum;
		for(int j=1;j<n;j++){
			m++;
			b[m].node1=j;
			cin>>s;
			b[m].node2=n;
			b[m].v=s;
		}
		//kul
		
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(find(a[b[i].node1])!=find(a[b[i].node2]))
				a[find(a[b[i].node1])]=a[find(a[b[i].node2])],
				ans+=b[i].v;
			
		}
		minn=min(minn,ans+sum);
		
		
	}
	cout<<minn;

	return 0;
}

