#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define sinzo return
#define code 0
#define pii pair<int,int> 
#define ex exit(0)
using namespace std;
const int N=2e6+10;
const int mod=1e9+7;
int b[N],c[N];
int n,m,k,l,cnt,sum[5],ans;
struct qaq
{
	int a,b,c,mx,fi,se,la,nxt,k[5],num[5];
}a[N];
priority_queue<pii,vector<pii>,greater<pii> >q1,q2,q3,q[4];
queue<int>mainq;
bool stone(int i)
{
	int fi=a[i].fi,se=a[i].se,la=a[i].la;
	if(sum[fi]<n/2)
	{
		sum[fi]++;
		q[fi].push({a[i].k[1],i});
		return 1;
	}
	int qf=q[fi].top().second;
	if(a[qf].k[a[qf].nxt-1]<a[i].k[1])
	{
		q[fi].push({qf,a[qf].k[a[qf].nxt]});
		//		ans-=a[qf].k[a[qf].nxt-1];
		mainq.push(qf);
		q[fi].pop();
		q[fi].push({i,a[i].k[1]});
		return 1;
	}
	//--------------------------------------------
	if(sum[se]<n/2)
	{
		sum[se]++;
		q[se].push({a[i].k[2],i});
		ans-=a[i].k[1];
		return 1;
	}
	qf=q[se].top().second;
	if(a[qf].k[a[qf].nxt-1]<a[i].k[1])
	{
		q[se].push({qf,a[qf].k[a[qf].nxt]});
		//		ans-=a[qf].k[a[qf].nxt-1];
		mainq.push(qf);
		q[se].pop();
		q[se].push({i,a[i].k[1]});
		return 1;
	}
	//--------------------------------------------
	if(sum[la]<n/2)
	{
		sum[la]++;
		q[la].push({a[i].k[3],i});
		ans-=a[i].k[2];
		return 1;
	}
	qf=q[la].top().second;
	if(a[qf].k[a[qf].nxt-1]<a[i].k[1])
	{
		q[la].push({qf,a[qf].k[a[qf].nxt]});
		//		ans-=a[qf].k[a[qf].nxt-1];
		mainq.push(qf);
		q[la].pop();
		q[la].push({i,a[i].k[1]});
		return 1;
	}
	//--------------------------------------------
	while(1)
	{
		cout<<"sinzo rp++\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].mx=max(max(a[i].a,a[i].b),a[i].c);
			
			a[i].a=a[i].a-a[i].mx;
			a[i].b=a[i].b-a[i].mx;
			a[i].c=a[i].c-a[i].mx;
			
			a[i].nxt=2;
			
			a[i].num[1]=a[i].a;
			a[i].num[2]=a[i].b;
			a[i].num[3]=a[i].c;
			
			ans+=a[i].mx;
			
			if(a[i].a==0)a[i].fi=1;
			if(a[i].b==0)a[i].fi=2;
			if(a[i].c==0)a[i].fi=3;
			
			if(a[i].a<=a[i].b&&a[i].a<=a[i].c&&a[i].fi!=1)a[i].la=1;
			if(a[i].b<=a[i].a&&a[i].b<=a[i].c&&a[i].fi!=2)a[i].la=2;
			if(a[i].c<=a[i].b&&a[i].c<=a[i].a&&a[i].fi!=3)a[i].la=3;
			
			a[i].se=6-a[i].fi-a[i].la;
			
			a[i].k[1]=a[i].num[a[i].fi]-a[i].num[a[i].se];
			a[i].k[2]=a[i].num[a[i].se]-a[i].num[a[i].la];
			a[i].k[3]=1e9+7;
			
			
		}
		for(int i=1;i<=n;i++)mainq.push(i);
		while(!mainq.empty())
		{
			int i=mainq.front();
			mainq.pop();
			stone(i);
		}
		cout<<ans<<endl;
		
		{
			for(int i=1;i<=n;i++)
			{
				a[i].a=a[i].b=a[i].c=a[i].mx=a[i].fi=a[i].se=a[i].la=0;
			}
			sum[1]=sum[2]=sum[3]=0;
			while(!q[1].empty())q[1].pop();
			while(!q[2].empty())q[2].pop();
			while(!q[3].empty())q[3].pop();
			ans=0;
		}
	}
	sinzo code;
}
/* 

2h AC(?) T1
请输入文本
luogu sinzo 873466

*/