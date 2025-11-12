#include <bits/stdc++.h>
using namespace std;
int da(int a,int b,int c,int d)
{
	int max=a,m[3]={a,b,c},id=0;
	for(int i=0;i<3;i++)
	 {
	 	if(m[i]>max)
	 	{
	 		max=m[i];
	 		id=i;
		}
	 }
	 if(d!=1)
	 {
	 	int h[2]={},ids[2]={};
	 	
		for(int i=0,j=0;i<3;i++)
		 {
		 	if(i!=id)
		 	{
		 		h[j]=m[i];
		 		ids[j]=i;
		 		j++;
			}
		 }
		 int q,w;
		 if(d==2)
		 {
		 	q=0,w=1;
		 }
		 else
		 {
		 	q=1,w=0;
		 }
		 if(h[0]>h[1])
		 {
		 	return ids[q];
		 }
		 else
		 {
		 	return ids[w];
		 }
	}
	 return id;
}
int gai(int s,int ss,int sss)
{
	int f[3]={s,ss,sss};
	int q=s;
	int r=f[da(s,ss,sss,2)];
	return (q-r);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int tt=0;tt<t;tt++)
	{
		long long n;
		cin>>n;
		long long s[n][3]={},d[n]={},s1[n]={},s2[n]={},s3[n]={},a=0,b=0,c=0;
		for(long long i=0;i<n;i++)
		{
			cin>>s[i][0]>>s[i][1]>>s[i][2];
			d[i]=da(s[i][0],s[i][1],s[i][2],1);
			if(d[i]==0)
			{
				s1[i]=1;
				s2[i]=0;
				s3[i]=0;
				a++;
			}
			else if(d[i]==1)
			{
				s1[i]=0;
				s2[i]=1;
				s3[i]=0;
				b++;
			}
			else
			{
				s1[i]=0;
				s2[i]=0;
				s3[i]=1;
				c++;
				
			}
		}
		if(a>(n/2))
		{
			for(int i=0;i<(a-(n/2));i++)
			{
				long long min=20001,id=0;
				for(long long j=0;j<n;j++)
				{
					if(s1[j]==1)
					{
						if(gai(s[j][0],s[j][1],s[j][2])<min)
						{
							min=gai(s[j][0],s[j][1],s[j][2]);
							id=j;
						}
					}
				}
				s1[id]=0;
				if(da(s[id][0],s[id][1],s[id][2],2)==1)
				{
					d[id]=1;
					s2[id]=1;
					b++;
				}
				else
				{
					d[id]=2;
					s3[id]=1;
					c++;
				}
			}
		}
		if(b>(n/2))
		{
			for(int i=0;i<(b-(n/2));i++)
			{
				long long min=20001,id=0;
				for(long long j=0;j<n;j++)
				{
					if(s2[j]==1)
					{
						if(gai(s[j][1],s[j][0],s[j][2])<min)
						{
							min=gai(s[j][1],s[j][0],s[j][2]);
							id=j;
						}
					}
				}
				s2[id]=0;
				if(da(s[id][0],s[id][1],s[id][2],2)==2)
				{
					d[id]=2;
//					s3[id]=1;
					a++;
				}
				else
				{
					d[id]=2;
//					s1[id]=1;
					c++;
				}
			}
		}
		if(c>(n/2))
		{
			for(int i=0;i<(c-(n/2));i++)
			{
				long long min=20001,id=0;
				for(long long j=0;j<n;j++)
				{
					if(s3[j]==1)
					{
						if(gai(s[j][2],s[j][0],s[j][1])<min)
						{
							min=gai(s[j][2],s[j][0],s[j][1]);
							id=j;
						}
					}
				}
				s3[id]=0;
				if(da(s[id][0],s[id][1],s[id][2],2)==1)
				{
					d[id]=1;
					s2[id]=1;
					b++;
				}
				else
				{
					d[id]=0;
					s1[id]=1;
					a++;
				}
			}
		}
		long long ans=0;
		for(long long i=0;i<n;i++)
		{
			ans+=s[i][d[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}
//1 4 0 1 0 0 1 0 0 2 0 0 2 0
