#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[20],sum[20][10010],fa[10020],num,cnt;
long long ans,res;
struct node{
	int u,v;
	long long w;
}a[1000010],b[200010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k,ans=LONG_LONG_MAX;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int U=find(a[i].u),V=find(a[i].v);
		if(U!=V)fa[V]=U,a[++num]=a[i];
		if(num==n-1)break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>sum[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
		num=n-1,res=0,cnt=n-1;
		for(int j=1;j<n;j++)b[j]=a[j];
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				res+=c[j+1],cnt++;
				for(int o=1;o<=n;o++){
					b[++num]={o,j+n+1,sum[j+1][o]};
				}
			}
		}
//		cout<<num<<" ";
		sort(b+1,b+num+1,cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=num;i++){
			int U=find(b[i].u),V=find(b[i].v);
//			cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<"\n";
			if(U!=V)fa[V]=U,cnt--,res+=b[i].w;//,cout<<b[i].w<<" "<<cnt<<"\n";
			if(cnt==0)break;
		}
		ans=min(ans,res);
//		cout<<"\n";
//		cout<<i<<" "<<res<<"\n";
	}
//	for(int i=1;i<=k;i++)cout<<c[i]<<" ";
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

6 5 2
1 2 1
2 3 100
3 4 1
4 5 100
5 6 1
1 100 100 100 1 1 100
1 100 1 1 100 100 100
307156942
505585650
505585650
*/
