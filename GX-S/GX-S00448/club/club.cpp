#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001],b[100001],c[100000],MAX = 0;
void az(int A,int B,int C,int k,long long z)
{
	if(z > MAX){MAX = z;}
	for(int i = k;i <= n;i++)
	{
		if(A < (n / 2))
		{
			az(A + 1,B,C,i + 1,z + a[i]);
		}
		if(B < (n / 2))
		{
			az(A,B + 1,C,i + 1,z + b[i]);
		}
		if(C < (n / 2))
		{
			az(A,B,C + 1,i + 1,z + c[i]);
		}
		
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t --)
	{
		MAX = 0;
		cin>>n;
		for(int i = 1;i <= n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		az(0,0,0,1,0);
		cout<<MAX<<endl;
	}
	return 0;
}
/*
 * #include<bits/stdc++.h>
using namespace std;
int n;
int a[100001],b[100001],c[100000],MAX = 0;
void az(int A,int B,int C,int k,long long z)
{
	if(z > MAX){MAX = z;}
	for(int i = k;i <= n;i++)
	{
		if(A < (n / 2))
		{
			az(A + 1,B,C,i + 1,z + a[i]);
		}
		if(B < (n / 2))
		{
			az(A,B + 1,C,i + 1,z + b[i]);
		}
		if(C < (n / 2))
		{
			az(A,B,C + 1,i + 1,z + c[i]);
		}
		
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t --)
	{
		MAX = 0;
		cin>>n;
		for(int i = 1;i <= n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		az(0,0,0,1,0);
		cout<<MAX<<endl;
	}
	return 0;
}
 */
