//补药看我源代码 
#include<bits/stdc++.h>
using namespace std;
struct nd{
	int ab1;
	int ab2;
	int ab3;
}st[100001];
int a[100001],b[100001],c[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		int s1=0,s2=0,s3=0;
		int s11=0,s22=0,s33=0;
		for(int j=1;j<=t;j++)
		{
			cin>>st[j].ab1>>st[j].ab2>>st[j].ab3;
		}
		if(t/2!=1)
		{
			for(int j=1;j<=t;j++)
			{
				if(st[j].ab1>st[j].ab2&&st[j].ab1>st[j].ab3)
				{
					a[j]=st[j].ab1;
					if(s11<t/2)
					{
						s1+=st[j].ab1;
					}
					s11++;
				}
				if(st[j].ab2>st[j].ab1&&st[j].ab2>st[j].ab3)
				{
					b[j]=st[j].ab2;
					if(s22<t/2)
					{
						s2+=st[j].ab2;
					}
					s22++;
				}
				if(st[j].ab3>st[j].ab1&&st[j].ab3>st[j].ab2)
				{
					c[j]=st[j].ab3;
					if(s33<t/2)
					{
						s3+=st[j].ab3;
					}
					s33++;
				}
			}
			if(s11>t/2)
			{
				s1=0;
				sort(a+1,a+t+1);
				for(int k=t;k>=t-(t/2)+1;k--)
				{
					s1+=a[k];
				}
			}
			if(s22>t/2)
			{
				s2=0;
				sort(b+1,b+t+1);
				for(int k=t;k>=t-(t/2)+1;k--)
				{
					s2+=b[k];
				}
			}
			if(s33>t/2)
			{
				s3=0;
				sort(c+1,c+t+1);
				for(int k=t;k>=t-(t/2)+1;k--)
				{
					s3+=c[k];
				}
			}
			cout<<s1+s2+s3<<endl;
		}
		if(t/2==1)
		{
			for(int j=1;j<=t;j++)
			{
				if(st[j-1].ab1>st[j-1].ab2&&st[j-1].ab1>st[j-1].ab3 &&st[j].ab1>st[j].ab2&&st[j].ab1>st[j].ab3 &&st[j-1].ab1>st[j].ab1)
				{
					cout<<st[j-1].ab2+st[j].ab1;
				}
				if(st[j-1].ab1>st[j-1].ab2&&st[j-1].ab1>st[j-1].ab3 &&st[j].ab1<st[j].ab2&&st[j].ab2>st[j].ab3 &&st[j-1].ab2>st[j].ab2)
				{
					cout<<st[j-1].ab1+st[j].ab2;
				}
				if(st[j-1].ab1>st[j-1].ab2&&st[j-1].ab1>st[j-1].ab3 &&st[j].ab1<st[j].ab3&&st[j].ab2<st[j].ab3 &&st[j-1].ab3>st[j].ab3)
				{
					cout<<st[j-1].ab1+st[j].ab3;
				}
				if(st[j-1].ab1<st[j-1].ab2&&st[j-1].ab2>st[j-1].ab3 &&st[j].ab1<st[j].ab3&&st[j].ab2<st[j].ab3 &&st[j-1].ab3>st[j].ab3)
				{
					cout<<st[j-2].ab1+st[j].ab3;
				}
				if(st[j-1].ab3>st[j-1].ab2&&st[j-1].ab1<st[j-1].ab3 &&st[j].ab1>st[j].ab2&&st[j].ab1>st[j].ab3 &&st[j-1].ab1>st[j].ab1)
				{
					cout<<st[j-1].ab3+st[j].ab1;
				}
			}
		}
	}
		
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
