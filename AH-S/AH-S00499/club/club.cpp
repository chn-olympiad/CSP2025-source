#include <bits/stdc++.h>
using namespace std;
long long n,maxn=0;
struct Stu
{
	int club1;
	int club2;
	int club3;
	long long lovemost;
	int love;
}
a[100010];
bool bb[100010];
long long gg[4];
void dfs(int start,int v,int lus)
{
	if (v==lus)
	{
		int c1=0,c2=0;
		for (int i=1;i<=n;i++)
		{
			if (bb[i]==1) c1=c1+a[i].club1;
			else c2=c2+a[i].club2;
		}
		int c=c1+c2;
		if (maxn<c) maxn=c;
		return;    
	}
	for (int i=start;i<=n;i++)
	    if (bb[i]==0)
	    {
			bb[i]=1;
			dfs(i+1,v+1,lus);
			bb[i]=0;
		}
}
bool com()
{
	for (int i=1;i<=n;i++)
	    if (a[i].club2!=0||a[i].club3!=0) return 1;
	return 0;	
}
bool com1()
{
	for (int i=1;i<=n;i++)
	    if (a[i].club3!=0) return 1;
	return 0;	
}
bool comn(Stu an,Stu bn)
{
	return an.club1>bn.club1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		memset(a,0,sizeof(a));
		memset(bb,0,sizeof(bb));
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i].club1>>a[i].club2>>a[i].club3;
		if (com()==0)
		{
			sort(a+1,a+n+1,comn);
			int num=0;
			for (int i=1;i<=n/2;i++)
			    num+=a[i].club1;
			cout<<num<<endl;
		}
		if (com1()==0)
		{
			for (int i=2;i<=n/2;i+=2)
			    dfs(1,0,i);
			cout<<maxn<<endl;
			maxn=0;
		}
		if (n==2)
		{
			a[1].lovemost=max(max(a[1].club1,a[1].club2),a[1].club3);
			a[2].lovemost=max(max(a[2].club1,a[2].club2),a[2].club3);
			if (a[1].lovemost==a[1].club1) a[1].love=1;
			if (a[1].lovemost==a[1].club2) a[1].love=2;
			if (a[1].lovemost==a[1].club3) a[1].love=3;
			if (a[2].lovemost==a[2].club1) a[2].love=1;
			if (a[2].lovemost==a[2].club2) a[2].love=2;
			if (a[2].lovemost==a[2].club3) a[2].love=3;
			
			if (a[1].love!=a[2].love) 
			{
				cout<<a[1].lovemost+a[2].lovemost;
				return 0;
			}
			else 
			{
				int kk=max(a[1].lovemost,a[2].lovemost);
				int cc;
				if (kk==a[1].lovemost) cc=2;
				else 
				{
					cc=1;
				}
				
				gg[1]=a[cc].club1;
				gg[2]=a[cc].club2;
				gg[3]=a[cc].club3;
				for (int i=1;i<=3;i++)
				    for (int j=i+1;j<=3;j++)
				        if (gg[i]>gg[j]) swap(gg[i],gg[j]);
				cout<<kk+gg[2];
			}
		}
	}
	return 0;
}
