#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(i%10<=0&&i%10<10)
		{
			cnt+=i;
		}
		i=i/10;
	}
	cout<<cnt;
	return 0;
} 
