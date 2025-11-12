#include<bits/stdc++.h>
using namespace std;
struct kkk{
	int u,v,w;
}a[1050005];
int c,b[15],f[1050005];
bool cmp(kkk x,kkk y){
	return x.w<y.w;
}
int find(int xx){
	if(xx==f[xx])
	return xx;
	return f[xx]=find(f[xx]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cnt=m;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		int mark=0;
		cin>>c;
		for(int j=1;j<=n;j++){
			scanf("%d",&b[j]);
			if(b[j]==0)
			mark=j;
		}
		for(int j=1;j<=n;j++){
			if(j!=mark){
				cnt++;
				a[cnt].u=mark;
				a[cnt].v=j;
				a[cnt].w=b[j];
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		f[i]=i;
	//	cout<<a[i].u<<a[i].v<<a[i].w;
	}
	int ff=0;
	long long ans=0;
	for(int i=1;;i++){
		int s=find(a[i].u);
		int t=find(a[i].v);
		if(s==t)
		continue;
		f[s]=t;
		ff++;
		ans+=a[i].w;
		if(ff==n-1)
		break; 
	}
	cout<<ans;
	return 0;
}
