#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int sr[100000+5][3+5],we[100000+5];
int da;
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	cin>>t;
	while(t>0)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>sr[i][1]>>sr[i][2]>>sr[i][3];
		}
		if(n==2)
		{
			cout<<max(sr[1][1]+sr[2][2],max(sr[1][1]+sr[2][2],max(sr[1][1]+sr[2][3],max(sr[1][2]+sr[2][1],max(sr[1][2]+sr[2][1],max(sr[1][2]+sr[2][3],max(sr[1][3]+sr[2][1],max(sr[1][3]+sr[2][2],sr[1][3]+sr[2][2]))))))));
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				we[i]=sr[i][1];
			}
			sort(we+1,we+n+1);
			for(int i=n;i>n/2;i--)
			{
				da+=we[i];
			}
			cout<<da;
		}
		t--;
	}
	return 0;
}