#include<bits/stdc++.h>
using namespace std;
int t,n,ans,qwe,asd,a1[1000005],a2[1000005],a3[1000005],ma[1000005];
int pc(int a,int b,int c)
{
	int qqq=max(a,max(b,c));
	return qqq;
}
int bmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	 {
		 cin>>n;
		 for(int j=1;j<=n;j++)
		  {
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a2[j]==a3[j]&&a2[j]==0) ans++;
			}
		 if(ans==n)
					{
						sort(a1+1,a1+1+n,bmp);
						for(int i=1;i<=n/2;i++)
						  qwe=qwe+a1[i];
						cout<<qwe<<endl;
						continue;
						 }
	      if(n==2)
					{
						int q1=a1[1]+a2[2];
						int q2=a1[1]+a3[2];
						int q3=a2[1]+a1[2];
						int q4=a2[1]+a3[2];
						int q5=a3[1]+a2[2];
						int q6=a3[1]+a1[2];
						int max1=max(max(q1,q2),max(max(q3,q4),max(q5,q6)));
						cout<<max1<<endl;
						continue;
					}
			for(int i=1;i<=n;i++)
						ma[i]=pc(a1[i],a2[i],a3[i]);
			for(int w=1;w<=n;w++)
			 asd=asd+ma[w];
			cout<<asd<<endl;
		 }
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
