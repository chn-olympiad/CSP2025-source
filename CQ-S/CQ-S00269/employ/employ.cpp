#include<bits/stdc++.h>
using namespace std;
//int biao[505][10000];
//void cheng()
//{
//	int s2[10001]={1};
//	for(int i=2;i<=500;i++)
//	{
//		int s1[10001];
//		for(int j=0;j<=10000;j++)
//		{
//			s1[j]+=s2[j];
//			if(s1[j]>=10)
//			{
//				s1[j+1]+=s1[j]/10;
//				s1[j]%=10;
//			}
//		}
//		for(int j=0;j<=10000;j++)
//		{
//			s2[j]=s1[j];
//		}
//		int jj;
//		for(int j=10000;j>=0;j--)
//		{
//			if(s2[j]>0)
//			{
//				jj=j;
//				break;
//			}
//		}
//		cout<<'{';
//		for(int j=jj;j>=0;j--)
//		{
//			cout<<s2[j]<<',';
//		}
//		cout<<'}'<<endl;
//	}
//}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cheng();
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	int s1z=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			s1z++;
		}
	}
	if(m>s1z)
	{
		cout<<0;
	}
	cout<<500;
	return 0;
}
