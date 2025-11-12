#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,q,ans,fs=1;
struct node
{
	string s1,s2;
	long long len,b1,b2;
}a[N];
string t1,t2;
long long len1,len2,lt,rt,lb1,lb2;
bool flag=1;
bool cmp(node a1,node a2)
{
	return a1.len<a2.len;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
		a[i].len=a[i].s1.size();
		for(long long j=0;fs&&j<a[i].len;j++)
		{
			if(a[i].s1[j]=='b')
			{
				if(a[i].b1) fs=0;
				a[i].b1=j;
			}
			if(a[i].s2[j]=='b')
			{
				if(a[i].b2) fs=0;
				a[i].b2=j;
			}
			if(a[i].s1[j]!='a'&&a[i].s1[j]!='b') fs=0;
			if(a[i].s2[j]!='a'&&a[i].s2[j]!='b') fs=0;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		len1=t1.size(),len2=t2.size();
		if(len1!=len2)
		{
			cout<<0<<endl;
			continue;
		}
		for(long long j=0;fs&&j<len1;j++)
		{
			if(t1[j]=='b')
			{
				if(lb1) fs=0;
				lb1=j;
			}
			if(t2[j]=='b')
			{
				if(lb2) fs=0;
				lb2=j;
			}
			if(t1[j]!='a'&&t1[j]!='b') fs=0;
			if(t2[j]!='a'&&t2[j]!='b') fs=0;
		}
		if(fs)
		{
			for(long long j=1;j<=n;j++)
			{
				if(lb1-lb2!=a[j].b1-a[j].b2) continue;
				if(lb1<a[j].b1||len1-lb1<a[j].len-a[j].b1) continue;
				ans++;
			}
		}
		else
		{
			lt=0,rt=len1-1,ans=0;
			while(lt<len1-1&&t1[lt]==t2[lt]) lt++;
			while(rt>0&&t1[rt]==t2[rt]) rt--;
			for(long long j=1;j<=n;j++)
			{
				for(long long st=rt-a[j].len+1;st<=lt;st++)
				{
					flag=0;
					for(long long now=st;!flag&&now-st<=a[j].len-1;now++)
					{
						if(a[j].s1[now-st]!=t1[now]||a[j].s2[now-st]!=t2[now]) flag=1;
					}
					if(!flag) ans++;
				}
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
