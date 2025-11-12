#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x*10+c-'0'),c=getchar();
	return x*f;
}
const int QAQ=1e5+19;
int t,n,a[QAQ][4];
priority_queue<int> dui1,dui2,dui3;
void chuli()
{
	while(!dui1.empty()) dui1.pop();
	while(!dui2.empty()) dui2.pop();
	while(!dui3.empty()) dui3.pop();
	int o1,o2,o3;
	o1=0,o2=0,o3=0;
	int ans=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) dui1.push(max(a[i][2],a[i][3])-a[i][1]),o1++,ans+=a[i][1];
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) dui2.push(max(a[i][1],a[i][3])-a[i][2]),o2++,ans+=a[i][2];
		else dui3.push(max(a[i][1],a[i][2])-a[i][3]),o3++,ans+=a[i][3];
	}
	if(o1>n/2)
	{
		while(o1>n/2)
		{
			ans+=dui1.top();
			dui1.pop();
			o1--;
		}
	}
	else if(o2>n/2)
	{
		while(o2>n/2)
		{
			ans+=dui2.top();
			dui2.pop();
			o2--;
		}
		
	}
	else
	{
		while(o3>n/2)
		{
			ans+=dui3.top();
			dui3.pop();
			o3--;
		}
	}
	printf("%d\n",ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int i=1;i<=t;i++) chuli();
	
	
	return 0;
}
/*
记得开快读。 

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0




n 为偶数？

先贪心分一下，如果合法直接输出。

如果不合法就把多出来的按最大值减次大值从小到大弹走。 


*/
