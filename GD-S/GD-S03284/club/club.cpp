#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct daan{
	long long data,bh;
};
struct ccc{
	daan data[4];
}a[100001];
long long T,n,ans=0,cnt[4];
bool cmp1(daan j,daan k)
{
	return j.data>k.data;
}
priority_queue<int,vector<int>,greater<int> >q;
void work()
{
	while(!q.empty())
	  q.pop();
	cin>>n;
	for(int z=1;z<=n;z++)
	{
		for(int y=1;y<4;y++)
		{
			cin>>a[z].data[y].data;
			a[z].data[y].bh=y;
		}
		sort(a[z].data+1,a[z].data+4,cmp1);
	}
	ans=0;
	for(int z=1;z<4;z++)
	  cnt[z]=0;
	for(int z=1;z<=n;z++)
	{
		cnt[a[z].data[1].bh]++;
		ans+=a[z].data[1].data;
	}
	long long mx=0,pos=0;
	for(int z=1;z<4;z++)
	{
		if(cnt[z]>mx)
		{
			pos=z;
			mx=max(mx,cnt[z]);
		}
	}
	if(mx>n/2)
	{
		for(int z=1;z<=n;z++)
		  if(a[z].data[1].bh==pos)
			q.push(a[z].data[1].data-a[z].data[2].data);
		while(q.size()>n/2)
		{
			ans-=q.top();
			q.pop();
		}
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int z=1;z<=T;z++)
	  work();
}/*
好想上迷惑行为大赏啊
先来点基础的
	freopen("clbu.in","r",stdin);
	freopen("culb.in","r",stdin);
	freopen("cubl.in","r",stdin);
	freopen("cblu.in","r",stdin);
	freopen("cbul.in","r",stdin);
本来想整个全排列的，可惜我太懒了

讲则笑话吧
众所周知，“乳”字可以形容幼年生物体，例如“乳鸽”，“乳猪”。
“奶”这个字也是一样
中国古代皇帝自称为“龙”
那皇子争皇位时会不会说
“我是奶龙！”
“我才是奶龙！” 
 
*/
