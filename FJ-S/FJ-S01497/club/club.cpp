#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int a,b,c;
}a[1000005];
int t,n,cnt1,cnt2,cnt3,ans;
priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
signed main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=cnt1=cnt2=cnt3=0;
		while(q1.size()) q1.pop();
		while(q2.size()) q2.pop();
		while(q3.size()) q3.pop();
		cin>>n;
		for(int i =1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			{
				cnt1++;
				ans+=a[i].a;
				q1.push(min(a[i].a-a[i].b,a[i].a-a[i].c));
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				cnt2++;
				ans+=a[i].b;
				q2.push(min(a[i].b-a[i].a,a[i].b-a[i].c));
			}
			else if(a[i].c>=a[i].a&&a[i].c>=a[i].b)
			{
				cnt3++;
				ans+=a[i].c;
				q3.push(min(a[i].c-a[i].a,a[i].c-a[i].b));
			}
		}
		while(cnt1>n/2)
		{
			ans-=q1.top();
			q1.pop();
			cnt1--;
		}
		while(cnt2>n/2)
		{
			ans-=q2.top();
			q2.pop();
			cnt2--;
		}
		while(cnt3>n/2)
		{
			ans-=q3.top();
			q3.pop();
			cnt3--;
		}
		cout<<ans<<'\n';
	}
	return 0; 
} 
