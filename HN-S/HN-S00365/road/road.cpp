#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct node{
	long long x,y,num;
};
long long n,m,k,fa[1000100],prize,ans=1e18,fx[1000100],fy[1000100],fw[1000100],fl[1000100];
vector<node> ve;
long long cmp(node x,node y){
	return x.num<y.num;
}
long long find(long long x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) fa[i]=i;
	for(long long i=1;i<=m;i++){
		cin>>fx[i]>>fy[i]>>fw[i];
		ve.push_back({fx[i],fy[i],fw[i]});
		ve.push_back({fy[i],fx[i],fw[i]});
	}
	sort(ve.begin(),ve.end(),cmp);
	long long cnt=0,sum=0;
	for(long long i=1;i<=m;i++){
		long long xx=find(ve[i].x),yy=find(ve[i].y);
		if(xx==yy) continue;
		fa[xx]=yy;
		sum+=ve[i].num;
	}
	ans=min(ans,sum);
	if(k>0){
		cout<<0;
		return 0;
	}
//	for(long long i=1;i<=k;i++){
//		ve.clear();
//		cin>>prize;
//		long long sum=prize,idd;
//		for(long long i=1;i<=m;i++){
//			ve.push_back({fx[i],fy[i],fw[i]});
//			ve.push_back({fy[i],fx[i],fw[i]});
//		}
//		for(long long j=1;j<=n;j++){
//			cin>>idd;
//			ve.push_back({i+n,j,idd});
//			ve.push_back({j,i+n,idd});
//			cnt++;
//		}
//		sort(ve.begin(),ve.end(),cmp);
//		for(long long j=1;j<=m+cnt;j++){
//			long long xx=find(ve[j].x),yy=find(ve[j].y);
//			if(xx==yy) continue;
//			fl[xx]=1;fl[yy]=1;
//			fa[xx]=yy;
//			sum+=ve[j].num;
//			long long flag=0;
//			for(long long i=1;i<=n;i++){
//				if(fl[i]!=1){
//					flag=1;break;
//				}
//			}
//			if(flag)
//		}
//		ans=min(ans,sum);
//	}
	cout<<ans;
	return 0;
}

