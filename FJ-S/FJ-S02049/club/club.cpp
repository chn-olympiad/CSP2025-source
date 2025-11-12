#include<bits/stdc++.h>
using namespace std;
vector<long long>cl1,cl2,cl3;
long long t,n;
long long a_1,a_2,a_3;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long i;
		cl1.clear();
		cl2.clear();
		cl3.clear();
		long long ans=0;
		for(i=1;i<=n;i++)
		{
			cin>>a_1>>a_2>>a_3;
			long long mx=max(a_1,max(a_2,a_3));
			if(mx==a_1)
			{
				cl1.push_back(a_1-max(a_2,a_3));
				ans+=a_1;
				continue;
			}
			if(mx==a_2)
			{
				cl2.push_back(a_2-max(a_1,a_3));
				ans+=a_2;
				continue;
			}
			if(mx==a_3)
			{
				cl3.push_back(a_3-max(a_1,a_2));
				ans+=a_3;
				continue;
			}
		}
		if(n/2<cl1.size())
		{
			sort(cl1.begin(),cl1.end()); 
			for(i=0;i<cl1.size()-n/2;i++)
			{
				ans-=cl1[i];
			}
		}
		if(n/2<cl2.size())
		{
			sort(cl2.begin(),cl2.end());
			for(i=0;i<cl2.size()-n/2;i++)
			{
				ans-=cl2[i];
			}
		}
		if(n/2<cl3.size())
		{
			sort(cl3.begin(),cl3.end());
			for(i=0;i<cl3.size()-n/2;i++)
			{
				ans-=cl3[i];
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
