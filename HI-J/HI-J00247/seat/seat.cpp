#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a=m*n;
	vector<int> x(a);
	int b;
	int sum=0;
	for(int i=0;i<a;i++)
	{
		int t;
		cin>>t;
		x.push_back(t);
		 if(i==0)
		 {
		 	b=t;
		 }
	}
	sort(x.begin(),x.end());
	reverse(x.begin(),x.end());
	for(int j=0;j<a;j++)
	{
		if(x[j]>=b)
		{
			sum++;
		}
		
	}
	int ans1=sum%m;
	int d=sum/m;
	if(sum%m==0&&d%2==0)
	{
		ans1++;
	}
	if(sum%m==0&&d%2!=0)
	{
		ans1+=3;
	}
	
	
	if(sum%m!=0&&d%2!=0)
	{
		ans1=m-ans1+1;
	}
	int ans2=sum/m+1;
	if(sum%m==0)
	{
		ans2--;
	}
	cout<<ans2<<" "<<ans1;
	return 0;
}
