//GZ-S00010 付滨诚 贵阳市南明区双龙华麟学校

/*
又是一年的CSP-S还是好紧张
看完第一题后感觉是个贪心 
但策略题目中给的好像并不明显
我自己尝试去找了一下
我的想法是，记录每个d[i]的前n/2个最大的数的和,然后从d[2],d[3]尝试反悔
每一次都取最优的，贪心感觉没问题，那就先写吧 
666,一个这么长的贪心太难写了，我们不妨换个思路
我们可以每一次都取三个的最大值，如果有一个被选中的数量大于n/2那就向上找另外两个数，并计算差值，每一次都选差值最小的那一个
并且，最多的那一组的数量会为n/2所以，我们只需要一次这样的操作即可 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Stu{
	int ii,jj,v;
}id[N];
int T,n,ans,d[N][4],sum[4],vis[N][4];
bool cmp(Stu x,Stu y){
	return x.v<y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum[1]=sum[2]=sum[3]=ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) vis[i][j]=0;
		for(int i=1;i<=n;i++) id[i].ii=id[i].jj=id[i].v=0;
		for(int i=1;i<=n;i++) cin>>d[i][1]>>d[i][2]>>d[i][3];
		for(int i=1;i<=n;i++){
			int maxn=INT_MIN,maxx=0;
			for(int j=1;j<=3;j++) if(d[i][j]>maxn) maxn=d[i][j],maxx=j;
			vis[i][maxx]=1;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) if(vis[i][j]) sum[j]++;
		bool f=0;
		int x=0,num=0;
		for(int i=1;i<=3;i++) if(sum[i]>n/2) f=1,x=i;
		num=sum[x]-n/2;
		if(f==0){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(vis[i][j]) ans+=d[i][j];
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(vis[i][x]){
				id[i].ii=i;
				if(x==1){
					if(d[i][2]>=d[i][3]) id[i].v=d[i][x]-d[i][2],id[i].jj=2;
					else id[i].v=d[i][x]-d[i][3],id[i].jj=3;
				}
				if(x==2){
					if(d[i][1]>=d[i][3]) id[i].v=d[i][x]-d[i][1],id[i].jj=1;
					else id[i].v=d[i][x]-d[i][3],id[i].jj=3;
				}
				if(x==3){
					if(d[i][1]>=d[i][2]) id[i].v=d[i][x]-d[i][1],id[i].jj=1;
					else id[i].v=d[i][x]-d[i][2],id[i].jj=2;
				}
			}
			else id[i].ii=i,id[i].jj=0,id[i].v=INT_MAX;
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=num;i++) if(id[i].ii!=0&&id[i].jj!=0&&id[i].v!=0) vis[id[i].ii][id[i].jj]=1,vis[id[i].ii][x]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) if(vis[i][j]) ans+=d[i][j];
		cout<<ans<<"\n";
	}
	return 0;
}
