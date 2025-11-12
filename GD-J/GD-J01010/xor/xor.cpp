#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
struct node{
	int x,y;
};
node ans[10000005];
bool vis[10000005];
int cnt=0;
bool cmp1(node n,node m){
	return n.y-n.x<m.y-m.x;
}
bool cmp(node n,node m){
	return n.y<m.y;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
			if((b[j]^b[i-1])==k){
				cnt++;
				ans[cnt]={i,j};
			}
		}
	}
	sort(ans+1,ans+cnt+1,cmp1);
	sort(ans+1,ans+cnt+1,cmp);
	int tot=0,end=0;
	for(int i=1;i<=cnt;i++){
		if(ans[i].x>end){
			end=ans[i].y;
			tot++;
		}
	}
	printf("%d",tot);
	return 0;
}
/*
恳求ccf的数据水一些orz orz orz orz orz
本来想用昨天的大凶保存rp的，但是昨天中平，rp又减了
这次没有一等奖我估计我也要没了
位运算也忘了，xor都是试出来的
最后的大数据成功寄飞，不仅长达9秒答案还不对 

从第四题回来，拿到了1~3，15~20的分，两个特判，其他不搞了，蒟蒻智商太低
S组由于初赛乱答，获得了44.5的好成绩，学校也没捞上来，美好的考试结束了，明天又要考道法和历史，我一点没背，寄 
压力有点大，明年可能就AFO了，估计是最后一次了
还有半个小时，摆烂了 

最后10分钟，不让去洗手间了。开摆， 前两题应该没问题，吧？
等下还要上课，我这悲惨的人生 
*/
