#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum[5],ans[5];
ll numa=0,numb=0,numc=0;
struct node{
	ll v[5],toa,tob,toc;
}a[1000010];
bool cmp1(node x,node y){return x.v[1]>y.v[1];}
bool cmp2(node x,node y){return x.v[2]>y.v[2];}
bool cmp3(node x,node y){return x.v[3]>y.v[3];}
int mian(){
	memset(sum,0,sizeof(sum));
	memset(ans,0,sizeof(ans));
	memset(a,0,sizeof(a));
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll ha,hb,hc;
		cin>>ha>>hb>>hc;
		sum[1]+=ha,sum[2]+=hb,sum[3]+=hc;
		if(ha>=hb) a[i].toc=1;
		else a[i].toc=2;
		if(ha>=hc) a[i].tob=1;
		else a[i].tob=3;
		if(hb>=hc) a[i].toa=2;
		else a[i].toa=3;
		
		a[i].v[1]=max(hb,hc)-ha;
		a[i].v[2]=max(ha,hc)-hb;
		a[i].v[3]=max(hb,ha)-hc;
	}
	numa=0,numb=0,numc=0;
	sort(a+1,a+n+1,cmp1);
	for(ll i=1;i<=n/2||(a[i].v[1]>0&&i<=n&&numb<(n/2)&&numc<(n/2));i++){
		ans[1]+=a[i].v[1];
		if(a[i].toa==2) numb++;
		else numc++;
	}
	ans[1]+=sum[1];
	
	numa=0,numb=0,numc=0;
	sort(a+1,a+n+1,cmp2);
	for(ll i=1;i<=n/2||(a[i].v[2]>0&&i<=n&&numa<(n/2)&&numc<(n/2));i++){
		ans[2]+=a[i].v[2];
		if(a[i].tob==1) numa++;
		else numc++;
	}
	ans[2]+=sum[2];
	
	ll numa=0,numb=0,numc=0;
	sort(a+1,a+n+1,cmp3);
	for(ll i=1;i<=n/2||(a[i].v[3]>0&&i<=n&&numb<(n/2)&&numa<(n/2));i++){
		ans[3]+=a[i].v[3];
		if(a[i].toc==1) numa++;
		else numb++;
	}
	ans[3]+=sum[3];
	cout<<max(ans[1],max(ans[2],ans[3]))<<endl;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) mian();
	return 0;
}//呜呜我怎么这么菜，，14:45想出来T1实现完代码已经15:21
//唉，收拾好心情下一题吧 
//完蛋了不会图论，又不会最短路又不会dfs搜索
//15:52敲出最短路代码，发现其实是最小生成树，重打
//16:04裸kruskal 
//16:17贩糖，我为什么要双向建边???
//16:27时间过半，T2性质A刚刚结束，心急如焚 
//16:55性质K<=5完成 时间并不理想 期望60pts 
//17:05开T3决定哈希暴力
//我服了....一直出错一直锅
//18:10暴力哈希初步据正确性，期望24pts
//AFOed，我真的学过oi吗？？难道真的用三年时间讲好一个笑话吗... 
