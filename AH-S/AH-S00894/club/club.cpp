#include<bits/stdc++.h>
using namespace std;
const long long N=20005;
long long s[N],t,n,a,b,c,s1,s2,s3,ss,maxn=-666,tt,t1,t2,t3;
int ey(long long a1,long long a2,long long a3)
{
	return max(a2,min(a1,a3));
}
int main()
{
	long long i,j;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
		{
			t1=a;
			t2=b;
			t3=c;
			cin>>a>>b>>c;
			tt=max(a,max(b,c));
			if(a>=b&&a>=c&&s1+1<=n/2)
			{
				s1++;
				ss+=a;
				//cout<<"ss="<<ss<<endl;
			}
			else if(b>=a&&b>=c&&s2+1<=n/2)
			{
				s2++;
				ss+=b;
				//cout<<"ss="<<ss<<endl;
			}
			else if(c>=b&&c>=a&&s3+1<=n/2)
			{
				s3++;
				ss+=c;
				//cout<<"ss="<<ss<<endl;
			}
			s[j]=ss;
			s[j]=max(s[j],tt+max(t2,min(t1,t3)));
			//cout<<"max(t2,min(t1,t3))=="<<max(t2,min(t1,t3))<<endl;
			//cout<<"tt="<<tt<<endl;
		}
		cout<<s[n]<<endl;
		ss=0;
		s1=0;
		s2=0;
		s3=0;
	}
	return 0;
}
