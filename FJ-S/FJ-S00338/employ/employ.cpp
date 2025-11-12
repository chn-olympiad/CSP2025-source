#include<iostream>
using namespace std;
int nai[10000];
int main()
{
	int n,m;
	int f=0;
	int p=0,g=0,cnt=0;
	freopen("employ.in","r",stdin);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>nai[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]==0)
		{
			f++;
			if(f==nai[i+1])
			{
				p++;
				f=0;
			}
		}
		else
		{
			g++;
		}
	}
	if(g==m)
	{
		cnt++;
	}
	
	freopen("employ.out","w",stdout);
	cout<<cnt;
	return 0;
}
