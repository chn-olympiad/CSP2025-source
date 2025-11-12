#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int t,n,ans;
int a[N],b[N],c[N];
int a1[N],b1[N];
priority_queue<pair<int,int> > q;
void solve(int n)
{
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>=0) 
		{	
			sum+=b[i];
			cnt++;
		}
		if(a[i]<0&&b[i]<0) q.push({max(a[i],b[i]),1});
		if(b[i]<0) q.push({a[i],1});
		q.push({a[i]-b[i],0});
	}
	int cntsum=0;
	int cnt2=cnt;
	while(!q.empty())
	{
		if((q.top().first<=0||cntsum>=cnt/2)&&cnt2>=n/2) break;
		sum+=q.top().first;
		cntsum++;
		cnt2+=q.top().second;
		cnt=cnt-(1-q.top().second);
		q.pop();
	}
	if(cnt>n/2)
	{
		while(!q.empty())
		{
			if(cnt<=n/2) break;
			if(1-q.top().second)
			{
				cnt--;
				sum+=q.top().first;
			}
			q.pop();
		}
	}
	ans+=sum;
	return;
}
int main()
{
	cin>>t;
	t=1;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>b1[i]>>c[i];
			a[i]=a1[i]-c[i];
			b[i]=b1[i]-c[i];
			ans+=c[i];
		}
		solve(n);
		cout<<ans;
	}
	return 0;
}
