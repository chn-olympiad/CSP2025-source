#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<ctime>
#include<cstdlib>
#define int long long
const int N=521;
const int M=998244353;
using namespace std;
char cvb;
int re()
{
	int dfg=0,fgh=1;
	cvb=getchar();
	while(cvb>'9'||cvb<'0')
	{
		if(cvb=='-') fgh=-1;
	cvb=getchar();
		}
	while(cvb>='0'&&cvb<='9')
	{
		dfg=(dfg<<1)+(dfg<<3)+cvb-'0';
	cvb=getchar();
		}
	return dfg*fgh;
}
int n,m,b[N],s[N],a[N],ans,pd1=0,pd2=1;
char c;
void blcqj(int now,int death)
{
   if(death>n-m) return;
   if(now==n+1)
   {
	   if(death<=n-m) ans++;
	   return;
	   }
   for(int i=1;i<=n;i++)
     if(!b[i])
     {
		 b[i]=1;
		 if(death>=a[i]||!s[now]) blcqj(now+1,death+1);
		 else blcqj(now+1,death);
		 b[i]=0;
	 }
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=re();
	m=re();
	for(int i=1;i<=n;i++) {c=getchar(); s[i]=c-'0'; if(!s[i]) pd1++;}
	for(int i=1;i<=n;i++) {a[i]=re(); if(!a[i]) pd2=0;}
	if(n==m){
	  if(!pd1&&pd2)
	  {
		  ans=1;
		  for(int i=1;i<=n;i++) ans=ans*i%M;
		  cout<<ans;
		  return 0;
	}
	else {cout<<0; return 0;}}
	if(pd1+m>n) {cout<<0; return 0;}
	blcqj(1,0);
	cout<<ans;
	return 0;          //RP++!
}
