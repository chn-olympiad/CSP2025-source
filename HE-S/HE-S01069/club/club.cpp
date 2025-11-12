#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k;
	cin>>k;
	for(int i = 0;i<k;i++)
	{
		int n;
		cin>>n;
		int p1[100000];
		int p2[100000];
		int p3[100000];
		for(int j = 0;j<n;j++)
		{
			cin>>p1[j]>>p2[j]>>p3[j];
		}
		sort(p1+0,p1+n);
		int mid = n/2;
		int ans = 0;
		for(int j = mid;j<n;j++)
		{
			ans += p1[j];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
