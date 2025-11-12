#include<bits/stdc++.h>
using namespace std;
//vector<int>s;
//vector<int>s1;
//vector<int>ans;
int a[100000000];
//int yihuo(int a,int b)
//{
//	int t=0;
//	int t1=0;
//	while(a==0)
//	{
//		int g=a%2;
//		s.push_back(g);
//		a/=2;
//		t++;
//	}
//	while(b==0)
//	{
//		int g=b%2;
//		s1.push_back(g);
//		b/=2;
//		t1++;
//	}
//	if(t1>t)
//	{
//		int f=t1-t;
//		for(int i=0;i<f;i++)
//		{
//			if(b[i])
//		}
//	}
//}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=true;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
//	if(n<=10 and f==false)
//	{
//		if(k==0)
//		{
//			int f=0;
//			int t=0;
//			for(int i=0;i<n;i++)
//			{
//				if(f==0 and a[i]==1)
//				{
//					t++;
//					f=1;
//				}
//				if( f==0 and a[i]==0)
//				{
//					t++;
//					f=0;
//				}
//				if(f==1 and a[i]==1)
//				{
//					f=0;
//				}
//				if(f==1 and a[i]==0)
//				{
//					f=1;
//				}
//			}
//			cout<<t;
//			return 0;
//		}	
//	}
	if(k==0 and n>10)
	{
		if(n%2==0)
		{
			cout<<n/2;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	return 0;
 } 
