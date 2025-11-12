#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int T,n,flag,flagb,maxn,ans;
struct stu{
	int a1,a2,a3;
	int dif;
}s[N];

bool cmp(stu a,stu b)
{
	return a.a1>b.a1;
}

bool cmq(stu a,stu b)
{
	return a.dif<b.dif;
}

int dfs(int lev,int l1,int l2,int l3,int fom)
{
	if(lev==n+1)return fom;
		if(l1!=0)
		{
			l1--;
			ans=max(ans,dfs(lev+1,l1,l2,l3,fom+s[lev].a1));
			l1++;
		}
		if(l2!=0)
		{
			l2--;
			ans=max(ans,dfs(lev+1,l1,l2,l3,fom+s[lev].a2));
			l2++;
		}
		if(l3!=0)
		{
			l3--;
			ans=max(ans,dfs(lev+1,l1,l2,l3,fom+s[lev].a3));
			l3++;
		}
		return 0;
}

int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   cin>>T;
   for(int g=1;g<=T;g++)
   {
	   ans=0;
	   flag=1,flagb=1;
	   cin>>n;
	   maxn=n/2;
	   for(int i=1;i<=n;i++)
	   {
		   cin>>s[i].a1>>s[i].a2>>s[i].a3;
		   if(flagb)
		   {
			   if(s[i].a3!=0){flagb=0;flag=0;}
			   if(flag)
			   {
				   if(s[i].a2!=0)flag=0;
				   }
		   }
	   }
	   if(flag)//A
	   {
		  sort(s+1,s+1+n,cmp);
		  for(int i=1;i<=maxn;i++)
		  {
			  ans+=s[i].a1;
		  }
		  cout<<ans<<endl;
	   }
	   else if(flagb)//B
	   {
		   for(int i=1;i<=n;i++)
		   {
			   ans+=s[i].a2;
			   s[i].dif=s[i].a1-s[i].a2;
		   }
		   sort(s+1,s+1+n,cmq);
		   for(int i=maxn+1;i<=n;i++)ans+=s[i].dif;
		   cout<<ans<<endl;
	   }
	   else//1-4
	   {
		  dfs(1,maxn,maxn,maxn,0);
		  cout<<ans<<endl;
	   }
   }

   return 0;
}
