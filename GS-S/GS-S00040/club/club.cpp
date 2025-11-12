#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans;
struct f
{
 int sa;
 int sb;
 int sc;
 int st;
};
f a[100010];
struct f2
{
 int sat;
 int num;	
};
f2 na[100010];
f2 nb[100010];
f2 nc[100010];
int ka,kb,kc;
int main()
{
 freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
 ios::sync_with_stdio(false);
 cin>>t;
 for(int tt=0;tt<t;tt++)
 {
  cin>>n;
  /*memset(a,"0",sizeof(a));
  memset(na,"0",sizeof(na));
  memset(nb,"0",sizeof(nb));
  memset(nc,"0",sizeof(nc)); */ 
  ka=1;
  kb=1;
  kc=1;
  ans=0;
  for(int i=1;i<=n;i++)//输入 
  {
   cin>>a[i].sa>>a[i].sb>>a[i].sc;
   a[i].st=i;
  }
  for(int i=1;i<=n;i++)//不计上限的储存 
  {
   if(a[i].sa>=a[i].sb&&a[i].sa>=a[i].sc)
   {
    na[ka].sat=a[i].sa;
    na[ka].num=i;
    ka++;
   }
   else if(a[i].sb>=a[i].sa&&a[i].sb>=a[i].sc)
   {
    nb[kb].sat=a[i].sb;
    nb[kb].num=i;
    kb++;
   }
   else if(a[i].sc>=a[i].sa&&a[i].sc>=a[i].sb)
   {
    nc[kc].sat=a[i].sc;
    nc[kc].num=i;
    kc++;
   }
  }
  ka--;
  kb--;
  kc--;
  if(ka>n/2)//调人 
  {
   for(int i=1;i<=ka;i++)
   {
    for(int j=1;j<=ka;j++)
    {
     int nj=na[j].num;
     int nj1=na[j+1].num;
     if(na[j].sat-max(a[nj].sb,a[nj].sc)<na[j+1].sat-max(a[nj1].sb,a[nj1].sc))
     {
      swap(na[j],na[j+1]);
	 }
	}
   }
   while(ka>n/2)
   {
    int ka2=na[ka].num;
    if(a[ka2].sb>=a[ka2].sc&&kb<n/2)
    {
     kb++;
     nb[kb].sat=a[ka2].sb;
     nb[kb].num=a[ka2].st;
	}
	else
	{
     kc++;
     nc[kc].sat=a[ka2].sc;
     nc[kc].num=a[ka2].st;	 
	}
	ka--;
   }
  }
  if(kb>n/2)
  {
   for(int i=1;i<=kb;i++)
   {
    for(int j=1;j<=kb;j++)
    {
     int nj=nb[j].num;
     int nj1=nb[j+1].num;
     if(nb[j].sat-max(a[nj].sa,a[nj].sc)<nb[j+1].sat-max(a[nj1].sa,a[nj1].sc))
     {
      swap(nb[j],nb[j+1]);
	 }
	}
   }
   while(kb>n/2)
   {
    int kb2=nb[kb].num;
    if(a[kb2].sa>=a[kb2].sc&&ka<n/2)
    {
     ka++;
     na[ka].sat=a[kb2].sa;
     na[ka].num=a[kb2].st;
	}
	else
	{
     kc++;
     nc[kc].sat=a[kb2].sc;
     nc[kc].num=a[kb2].st;	 
	}
	kb--;
   }
  }
  if(kc>n/2)
  {
   for(int i=1;i<=kc;i++)
   {
    for(int j=1;j<=kc;j++)
    {
     int nj=nc[j].num;
     int nj1=nc[j+1].num;
     if(nc[j].sat-max(a[nj].sa,a[nj].sb)<nc[j+1].sat-max(a[nj1].sa,a[nj1].sb))
     {
      swap(nc[j],nc[j+1]);
	 }
	}
   }
   while(kc>n/2)
   {
    int kc2=nc[kc].num;
    if(a[kc2].sa>=a[kc2].sb&&ka<n/2)
    {
     ka++;
     na[ka].sat=a[kc2].sa;
     na[ka].num=a[kc2].st;
	}
	else
	{
     kb++;
     nb[kb].sat=a[kc2].sb;
     nb[kb].num=a[kc2].st;	 
	}
	kc--;
   }
  }
  for(int i=1;i<=ka;i++)
  {
   ans=ans+na[i].sat;
  }
  for(int i=1;i<=kb;i++)
  {
   ans=ans+nb[i].sat;
  }
  for(int i=1;i<=kc;i++)
  {
   ans=ans+nc[i].sat;
  }
  cout<<ans<<endl;
 }
 return 0;
}
