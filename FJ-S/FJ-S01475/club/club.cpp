#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct Student
{
	int a[4];
}a[100005];
int in[100005];
struct To
{
	int add,st,to,pre;
	
	To(int a,int b,int c,int d):add(a),st(b),to(c),pre(d){}
};
struct Compera
{
	bool operator()(const To& a,const To& b)
	{
		return a.add < b.add;
	}
};
priority_queue<To,vector<To>,Compera> q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t --)
	{
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;++ i)
		{
			scanf("%d%d%d",&a[i].a[1],&a[i].a[2],&a[i].a[3]);	
			ans += a[i].a[1];
			in[i] = 1; 
			q.push(To(a[i].a[2] - a[i].a[1],i,2,1));
			q.push(To(a[i].a[3] - a[i].a[1],i,3,1));
		}
		int num[4] = {0,n,0,0};
		n /= 2;
		while(q.top().add > 0)
		{
			To x = q.top();
			q.pop();
//			cout <<in[x.st] << ' ' <<x.to <<' ' <<x.add<< '\n';
			if(in[x.st] != x.pre)continue;
			if(x.to == x.pre)continue;
			-- num[in[x.st]];
			++ num[x.to];
			in[x.st] = x.to;
			ans += x.add;
			int y = in[x.st];
			if(y != 1)q.push(To(a[x.st].a[1] - a[x.st].a[y],x.st,1,y));
			if(y != 2)q.push(To(a[x.st].a[2] - a[x.st].a[y],x.st,2,y));
			if(y != 3)q.push(To(a[x.st].a[3] - a[x.st].a[y],x.st,3,y));
			if(q.empty())break;
		}
		while(!q.empty())q.pop(); 
		int c;
		if(num[1] > n)c = 1;
		if(num[2] > n)c = 2;
		if(num[3] > n)c = 3;
		for(int i = 1;i <= n * 2;++ i)
		{
			if(in[i] == c)
			{
				if(c != 1)q.push(To(a[i].a[1] - a[i].a[c],i,1,c));
				if(c != 2)q.push(To(a[i].a[2] - a[i].a[c],i,2,c));
				if(c != 3)q.push(To(a[i].a[3] - a[i].a[c],i,3,c));
			}
		}
		while(num[1] > n || num[2] > n || num[3] > n)
		{
			To x = q.top();
			q.pop();
//			cout << x.pre << '\n'; 
			if(in[x.st] != c)continue;
			ans += x.add;
			-- num[c];
			++ num[x.to];
			in[x.st] = x.to; 
		}
		printf("%d",ans);
	}
	return 0;
}
