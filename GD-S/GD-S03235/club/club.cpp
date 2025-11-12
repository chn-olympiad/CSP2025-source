#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int t,n,s[3];
ll a[N][3];
struct node{
	ll id,sz;
}b[3],my[N][3];
bool cmp(node n1,node n2)
{
	return n1.sz<n2.sz;
}
void fun1(int x)
{
	b[0].id=0,b[0].sz=a[x][0];
	b[1].id=1,b[1].sz=a[x][1];
	b[2].id=2,b[2].sz=a[x][2];
} 
void fun2(int x)
{
	my[x][0].id=b[2].id,my[x][0].sz=b[2].sz;//第一满意 
	my[x][1].id=b[1].id,my[x][1].sz=b[1].sz;//第二 
	my[x][2].id=b[0].id,my[x][2].sz=b[0].sz;//第三 
}
void work()
{
	int ans=0;
	memset(s,0,sizeof(s));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		fun1(i);
		sort(b,b+3,cmp);//满意度从低到高排序
		fun2(i);
		s[b[2].id]++;
		ans+=b[2].sz;
	}
	int zdbh=0,cdbh=0,cz=0;
	for(int i=0;i<3;i++)
	{
		if(s[i]>s[zdbh])
		{
			cdbh=zdbh;
			zdbh=i;
		}
		else if(s[i]>s[cdbh])
			cdbh=i;
	}
	if(s[zdbh]>n/2)
	cz=max(0,s[zdbh]-n/2);
	int c[N],cnt=0;
	for(int i=1;i<=n;i++)
		if(my[i][0].id==zdbh)
			c[++cnt]=my[i][0].sz-my[i][1].sz;
	sort(c+1,c+1+cnt);
	for(int i=1;i<=cz;i++)
		ans-=c[i];
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2 
//10 9 8
//4 0 0
