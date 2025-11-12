#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	long long  n,key,sum=0;
	cin>>n>>key;
	s.resize(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	long long m=1;
	long long nm;
	long long another=0;
	while(m<=n)
	{	
		bool flag=true;
		nm=m; 
		do
		{
			if(nm>n)
			{
				flag=false;
				break;
			}
			another=another^s[nm];
			nm++;
		}while(another!=key);
		if(flag==false)
		{
			m++;
		}
		else
		{
			m=nm; 
			sum++;
		}
		another=0;
	}
	cout<<sum;
	
	
	return 0;
}