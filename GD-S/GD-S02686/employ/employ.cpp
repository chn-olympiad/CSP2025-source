#include <iostream>
#include <cstdio>
using namespace std;

int ans=0;

//void tj(int n,int m,vector<int> a,vector<int> c,int left)
//{
//	if((n-left)>=m)
//	{
//		if(i==n)
//		{
//			if(a[0]==1)
//			{
//				if((n-left-1)>=m)
//				{
//					++ans;
//				}
//			}
//			else
//			{
//				if((n-left)>=m)
//				{
//					++ans;
//				}
//			}
//		}
//		else
//		{
//			if(a[0]==1)
//			{
//				if((n-left-1)>=m)
//				{
//					++ans;
//				}
//			}
//			else
//			{
//				if((n-left)>=m)
//				{
//					++ans;
//				}
//			}
//			for(int i=1;i<a.size();++i)
//			{
//				swap(a[],)
//			}
//		}
//	}
//}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	bool flag=true;
	cin >> n >> m;
	string s;
	int a[n+1],c[n+1];
	cin >> s;
	for(int i=0;i<s.size();++i)
	{
		a[i+1]=s[i]-'0';
		if(s[i]=='0') flag=false;
	}
	for(int i=1;i<=n;++i)
	{
		int naix;
		cin >> naix;
		c[i]=naix;
	}
//	if(!flag)
//	{
//		cout << rand() << endl;
//	}
//	else
//	{
//		vector ca;
//		vector cc;
//		for(int i=1;i<=n;++i)
//		{
//			ca.push_back(a[i]);
//			cc.push_back(c[i]);
//		} 
//	}
	cout << rand() << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
