#include<bits/stdc++.h>//14:40
using namespace std;//long long--
const int N=1e5+11;
int a[N],b[N],c[N],aa,bb,cc;
priority_queue<int> q;
struct zhx{
	int a,b,c;
}d[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,sum;
	cin>>T;
	while(T--)
	{
		aa=bb=cc=sum=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
		for(int i=1; i<=n; i++)
		{
			if(d[i].a>d[i].b && d[i].a>d[i].c)
				a[++aa]=i,sum+=d[i].a;
			else if(d[i].b>=d[i].a && d[i].b>=d[i].c)
				b[++bb]=i,sum+=d[i].b;
			else
				c[++cc]=i,sum+=d[i].c;
		}
		if(aa<=n/2 && bb<=n/2 && cc<=n/2)
		{
			printf("%d\n",sum);
			continue;
		}
		if(aa>n/2)
			for(int i=1; i<=aa; i++)
				q.push(-(d[a[i]].a-max(d[a[i]].b,d[a[i]].c)));
		if(bb>n/2)
			for(int i=1; i<=bb; i++)
				q.push(-(d[b[i]].b-max(d[b[i]].a,d[b[i]].c)));
		if(cc>n/2)
			for(int i=1; i<=cc; i++)
				q.push(-(d[c[i]].c-max(d[c[i]].b,d[c[i]].a)));
//		for(int i=1; i<=bb; i++)
//			cout<<b[i]<<endl;
//		cout<<"------------\n";
		for(int i=1; i<=max(aa,max(bb,cc))-n/2; i++)
		{
//			cout<<q.top()<<endl;
			sum-=(-q.top());
			q.pop();
		}
		while(!q.empty())
			/*cout<<q.top()<<endl,*/q.pop();
//		cout<<"------------\n";
		printf("%d\n",sum);
	}
	return 0;
}
//14:58 1.1k
//15:06 
//15:11
/*

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

*/
