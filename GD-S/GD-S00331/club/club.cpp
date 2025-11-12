#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int a;
	int b;
	int c;
}s[10005];
int maxx(int a,int b,int c)
{
	return max(a,max(b,c));
}
bool cmp(stu x,stu y)
{
	if(x.a!=y.a)	return x.a>y.a;
	if(x.b!=y.b)	return x.b>y.b;
	return x.c>y.c;	
}
long long t,n,cnt,k1,k2,k3,mmax=-1;
void dfs(int i,int j,int b1,int b2,int b3,long long cn)
{
	if(b1<0||b2<0||b3<0)	return ;
	if(i==n)
	{
		mmax=max(mmax,cn);
		return ;
	}
	dfs(i+1,1,b1-1,b2,b3,cn+s[i].a);
	dfs(i+1,2,b1,b2-1,b3,cn+s[i].b);
	dfs(i+1,3,b1,b2,b3-1,cn+s[i].c);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt=0;
		for(int i=0;i<n;i++)	cin>>s[i].a>>s[i].b>>s[i].c;
		if(n<=20)
		{
			mmax=-1;
			dfs(0,1,n/2,n/2,n/2,0);
			cout<<mmax<<endl;
		}
		else
		{
			k1=n/2,k2=n/2,k3=n/2;
			sort(s,s+n,cmp);
			for(int i=0;i<n;i++)
			{
				if(maxx(s[i].a,s[i].b,s[i].c)==s[i].a)
				{
					if(k1==0)
					{
						if(max(s[i].b,s[i].c)==s[i].b)
						{
							if(k2==0)
							{
								cnt+=s[i].c;
								k3--;
							}
							else
							{
								cnt+=s[i].b;
								k2--;
							}
						}
						else
						{
							if(k3==0)
							{
								cnt+=s[i].b;
								k2--;
							}
							else
							{
								cnt+=s[i].c;
								k3--;
							}
						}
					}
					else
					{
						cnt+=s[i].a;
						k1--;
					}
				}
				if(maxx(s[i].a,s[i].b,s[i].c)==s[i].b)
				{
					if(k1==0)
					{
						if(max(s[i].a,s[i].c)==s[i].a)
						{
							if(k1==0)
							{
								cnt+=s[i].c;
								k3--;
							}
							else
							{
								cnt+=s[i].a;
								k1--;
							}
						}
						else
						{
							if(k3==0)
							{
								cnt+=s[i].a;
								k1--;
							}
							else
							{
								cnt+=s[i].c;
								k3--;
							}
						}
					}
					else
					{
						cnt+=s[i].b;
						k2--;
					}
				}
				if(maxx(s[i].a,s[i].b,s[i].c)==s[i].c)
				{
					if(k1==0)
					{
						if(max(s[i].a,s[i].b)==s[i].a)
						{
							if(k1==0)
							{
								cnt+=s[i].b;
								k2--;
							}
							else
							{
								cnt+=s[i].a;
								k1--;
							}
						}
						else
						{
							if(k2==0)
							{
								cnt+=s[i].a;
								k1--;
							}
							else
							{
								cnt+=s[i].b;
								k2--;
							}
						}
					}
					else
					{
						cnt+=s[i].c;
						k3--;
					}
				}
			}
			cout<<cnt<<endl;
		}
	} 
	
	return 0;
} 
//先骗个20分再说
//是的我是来骗分的 
