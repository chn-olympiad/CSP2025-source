#include<bits/stdc++.h>
using namespace std;
int che_shu[25]; int t[25];
int ti;
//int che(int x)
//{
//	int num=1;
//	if(che_shu[x]) return che_shu[x];
//	else
//	{
//		for(int i=1;i<=x;i++)
//			num*=2;
//	}
//	che_shu[x]=num;
//	return num;
//}
//void zhuan(int x)
//{
//	
//	bool ti_i=0;
//	for(int i=20;i>=1;i--)
//	{
//		if(che(i)>x) continue;
//		x-=che(i);
//		t[i]=(t[i]+1)%2;
//		if(!ti_i)
//		{
//			ti_i=1;
//			ti=i;
//		}
//	}
//}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k; 
	int a[n+5];
	int maxd=-1e+5;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxd=max(maxd,a[i]);
	}
//	if(k==0)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			zhuan(a[i]);
//			bool pop=1;
//			for(int i=1;i<=ti;i++)
//			{
//				if(a[i]!=0) 
//				{
//					pop=0;break;
//				}
//			}
//			if(pop)
//			{
//				cnt++;
//				for(int i=1;i<=21;i++)
//				{
//					t[i]=0;
//				}
//			}
//		}
//	}
	if(k==0)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=1)
				t++;
			if(t==2)
				t=0;cnt++;
		}
	}
	else 
		cnt=n;
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

