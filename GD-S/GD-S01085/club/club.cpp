#include<bits/stdc++.h>
using namespace std;
#define N 100010
int t,n;
struct node{
	int a,b,c;
}a[N];
bool cmp(node x,node y)
{
	if(x.a==y.a&&x.b==y.b) return x.c>y.c;
	if(x.a==y.a) return x.b>y.b;
	return x.a>y.a;
}
struct NN{
	int ff,ss;
	bool operator < (const NN &x) const
	{
		return x.ff<ff;
	}
};
priority_queue<NN>q1,q2,q3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<'\n';
			NN w;
			int x=a[i].a,y=a[i].b,z=a[i].c;
			if(q1.size()>=n/2) x-=q1.top().ff;
			if(q2.size()>=n/2) y-=q2.top().ff;
			if(q3.size()>=n/2) z-=q3.top().ff;
	//		if(i==7) cout<<x<<' '<<y<<' '<<z<<'\n';
			if(x>=y&&x>=z){
				if(q1.size()>=n/2)
				{
					w=q1.top();
					q1.pop();
					if((a[w.ss].b>a[w.ss].c&&q2.size()<n/2)||q3.size()>=n/2) q2.push((NN){a[w.ss].b-max(a[w.ss].a,a[w.ss].c),w.ss});
					else q3.push((NN){a[w.ss].c-max(a[w.ss].a,a[w.ss].b),w.ss});
				}
				q1.push((NN){a[i].a-max(a[i].b,a[i].c),i});
			//	cout<<i<<'\n';
			}else if(y>=x&&y>=z){
				if(q2.size()>=n/2)
				{
					w=q2.top();
					q2.pop();
					if((a[w.ss].a>a[w.ss].c&&q1.size()<n/2)||q3.size()>=n/2) q1.push((NN){a[w.ss].a-max(a[w.ss].b,a[w.ss].c),w.ss});
					else q3.push((NN){a[w.ss].c-max(a[w.ss].a,a[w.ss].b),w.ss});
				}
				q2.push((NN){a[i].b-max(a[i].a,a[i].c),i});
			//	cout<<i<<'\n';
			}else{
				if(q3.size()>=n/2)
				{
					w=q3.top();
					q3.pop();
		//			if(w.ss==7) cout<<i<<'\n';
					if((a[w.ss].a>a[w.ss].b&&q1.size()<n/2)||q2.size()>=n/2) q1.push((NN){a[w.ss].a-max(a[w.ss].b,a[w.ss].c),w.ss});
					else q2.push((NN){a[w.ss].b-max(a[w.ss].a,a[w.ss].c),w.ss});
				}
				q3.push((NN){a[i].c-max(a[i].a,a[i].b),i});
			//	cout<<i<<'\n';
			}
		}
//		cout<<"1:";
		while(q1.size()) ans+=a[q1.top().ss].a,q1.pop();
	//	cout<<'\n'<<"2:";
		while(q2.size()) ans+=a[q2.top().ss].b,q2.pop();
	//	cout<<'\n'<<"3:";
		while(q3.size()) ans+=a[q3.top().ss].c,q3.pop();
	//	cout<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
} 
