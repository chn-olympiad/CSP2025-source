#include<bits/stdc++.h>
using namespace std;
long long m,n,k,l,p,ans,n1;
string b[10005],c[10005],q2,q3;
char q[1000005],w[1000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n1;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i]>>c[i];
	}
	for(int i=1;i<=n1;i++)
	{
		scanf("%s%s",q,w);
		long long h=strlen(q);
		n=999999999;
		for(long long j=0;j<h;j++)
		{
			if(q[j]!=w[j])
			{
				m=j;
				n=min(n,j);
			}
		 } 
		 for(int j=n;j>=0;j--)
		 {
		 	for(int k=m;k<h;k++)
		 	{
		 		q2=q[k];
		 		q3=w[k];
		 		for(int ol=k-1;ol>=j;ol--)
		 		{
		 			q2=q[ol]+q2;
				 }
				 for(int ol=k-1;ol>=j;ol--)
		 		{
		 			q3=w[ol]+q3;
				 }
				 
				 for(int ol=1;ol<=m;ol++)
				 {
				 	
				 	if(q2==b[ol]&&q3==c[ol])
					 {
					 	ans++;
					  } 
				 }
				 q2=' ';
				 q3=' ';
			 }
		 }
		 cout<<ans<<"\n";
		 ans=0;
	}
	return 0;
}
