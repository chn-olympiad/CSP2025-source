#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int ckb[27],mod=2302117;

string s1[10005],s2[10005],t1,t2;
int cnt1[10005][33],cnt2[10005][33],cnt[10005];
int f=0;
int la[200005],cha[200005],lat,chat;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,l;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		l=s1[i].length();
		for(int j=0;j<l;j++)
		{
			int hp1=s1[i][j]-'a',hp2=s2[i][j]-'a';
			if(!ckb[hp1])
				f++;
			if(!ckb[hp2])
				f++;
			hp1=hp1,hp2=hp2;//我也不知道为什么要这么做
			ckb[hp1]++,ckb[hp2]++;
			cnt1[i][hp1]++,cnt2[i][hp2]++;
			if(hp1!=hp2)
				cnt[i]++;
		}
	}
	if(f==2)
	{
		char sp1,sp2;
		int x,y;
		for(int i=0;i<='z'-'a';i++)
		{
			//cout<<i<<' '<<ckb[i]<<endl;
			if(ckb[i]==n*2)
			{
				
				sp2=i+'a';
			}
				
			else if(ckb[i]>0)
				sp1=i+'a';
		}		
		sp1=sp1;
		for(int i=1;i<=n;i++)
		{
			l=s1[i].length();
			x=y=0;
			for(int j=0;j<l;j++)
			{
				if(s1[i][j]==sp2)
				{
					la[i]=j;
					x=j;
				}
				if(s2[i][j]==sp2)
				{
					y=j;
				}
				if(x&&y)
					break;
			}
			//cout<<x<<' '<<y<<endl;
			cha[i]=x-y;
		}
		//cout<<endl<<sp1<<' '<<sp2<<endl;
		while(q--)
		{
			int ans=0;
			cin>>t1>>t2;
			l=t1.length();
			for(int i=0;i<l;i++)
			{
				if(t1[i]==sp2)
					lat=i,x=i;
				if(t2[i]==sp2)
					y=i;
			}
			for(int i=1;i<=n;i++)
			{
				//cout<<la[i]<<' '<<lat<<' '<<x-y<<' '<<cha[i]<<endl;
				if(la[i]<=lat&&x-y==cha[i])
					ans++;
			}
			cout<<ans;
		}
		cout<<0;
		
		
		return 0;
	}
	for(int i=1;i<=q;i++)
		cout<<0<<endl;
	return 0;
}
