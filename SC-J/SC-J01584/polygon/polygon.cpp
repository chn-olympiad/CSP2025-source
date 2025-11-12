#include<bits/stdc++.h>
using namespace std;
int n,m,s[5010],k;
set<string>z;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=3;i<=n;i++)
	{
		
		for(int j=1;j<=n-i+1;j++)
		{
			int ma=0,sum=0;
			string d=" ";
			for(int r=j;r<=j+i-1;r++)
			{
				max(ma,s[r]);
				sum+=s[r];
				d+=to_string(s[r]);
			}
			if(ma*2<sum)z.insert(d);
			
		}
	}
	cout<<z.size();
	return 0;
}