#include<bits/stdc++.h>
using namespace std;
long long int t,n,a[100001],b[100001],c[100001],cnt1,cnt2,cnt3,ans;
priority_queue<long long int> q1,q2,q3;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		cin>>n;cnt1=cnt2=cnt3=ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) cnt1++,ans+=a[i],q1.push(max(b[i],c[i])-a[i]);
			else if(b[i]>=c[i]) cnt2++,ans+=b[i],q2.push(max(a[i],c[i])-b[i]);
			else cnt3++,ans+=c[i],q3.push(max(a[i],b[i])-c[i]);
		}
		while(cnt1>n/2) cnt1--,ans+=q1.top(),q1.pop();
		while(cnt2>n/2) cnt2--,ans+=q2.top(),q2.pop();
		while(cnt3>n/2) cnt3--,ans+=q3.top(),q3.pop();
		cout<<ans<<'\n';
	}
}
