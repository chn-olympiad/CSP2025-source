#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int MOD=998244353;
ll n,a[114514],ans,b[114514],total,maxn,t[114514]; 
void dsf(ll now,ll total,ll maxn,ll num,bool geted)
{
	if(total>2*maxn&&num>=3&&geted) 
	{
//		for(int i=1;i<=num;i++) cout<<b[i]<<" ";
		ans=(ans+1)%MOD;
//		cout<<endl<<endl;
	}
	if(now>n) return;
	b[num+1]=now;
//	cout<<"要"<<now<<endl;
	dsf(now+1,total+a[now],max(a[now],maxn),num+1,1);
//	cout<<"不要"<<now<<endl;
	dsf(now+1,total,maxn,num,0);
	return;
}
//void sdf(ll sz,ll tot,ll mxn)
//{
//	
//}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		total+=a[i];
		t[a[i]]++;
	}
	dsf(1,0,0,0,0);
//	sdf(n,total,maxn);
	cout<<ans;
	return 0;
}
//直接dfs吧,但是怎么去重啊 哦哦哦不用去重 
//2^n大概6点 
//能不能全排列？？ 
//不能。
//好吧，就6个点吧100+100+50?+30?=280?
//屏幕前的家人们觉得我能省一吗？ 
//sto sto sto sto sto 西西弗 orz orz orz orz orz
/*
DELTARUNE
吊塔润 臂掉了 
*/
//有没有什么数学方法？？？
//能不能先从全选起手再挨个删？
//没啥区别……吗？
//试试 
//用桶储存个数
//这样每删一个就用桶判断最大值变不变 
//饿啊，没时间写了！！！ nooo！ 