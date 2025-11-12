#include<bits/stdc++.h>
using namespace std;
int n,q,ls[200020],rs[200020],lt[200020],rt[200020],s[200020],cds[200020],cdt[200020],cnt,srt[200020],trt[200020],sum[5400010],_;
int st1[5000010],st2[5000010];
const int mod1=998244353,mod2=1e9+7;
int hs11[200020],hs12[200020],hs21[200020],hs22[200020],ht11[200020],ht12[200020],ht21[200020],ht22[200020];
string s1[200020],s2[200020],t1[200020],t2[200020];
map<pair<pair<int,int>,pair<int,int> >,int>mp1;
map<pair<int,pair<pair<int,int>,pair<int,int> > >,int>mp4;
map<pair<int,int>,int>mp2,mp3;
void build(int now,int x,int a,int b,int stt,int ha1,int ha2,int hb1,int hb2,int c1,int c2)
{
	mp4[make_pair(stt,make_pair(make_pair(ha1,ha2),make_pair(hb1,hb2)))]=now;
	if(a<ls[x]-1)
	{
		a++;
		int _=s1[x][ls[x]-a]-'a'+1,y;
		if(mp2[make_pair(now,_)]!=0)
		{
			y=mp2[make_pair(now,_)];
		}
		else
		{
			cnt++;
			mp2[make_pair(now,_)]=cnt;
			y=cnt;
		}
		ha1=((long long)ha1+_*c1%mod1)%mod1;
		ha2=((long long)ha2+_*c2%mod2)%mod2;
		c1=(long long)c1*31%mod1;
		c2=(long long)c2*31%mod2;
		build(y,x,a,b,stt,ha1,ha2,hb1,hb2,c1,c2);
	}
	else if(b<cds[x]-rs[x])
	{
		if(b==0)
		{
			c1=1;
			c2=1;
		}
		b++;
		int _=s1[x][rs[x]+b]-'a'+1,y;
		if(mp3[make_pair(now,_)]!=0)
		{
			y=mp3[make_pair(now,_)];
		}
		else
		{
			cnt++;
			mp3[make_pair(now,_)]=cnt;
			y=cnt;
		}
		hb1=((long long)hb1+_*c1%mod1)%mod1;
		hb2=((long long)hb2+_*c2%mod2)%mod2;
		c1=(long long)c1*31%mod1;
		c2=(long long)c2*31%mod2;
		build(y,x,a,b,stt,ha1,ha2,hb1,hb2,c1,c2);
	}
	else
	{
		sum[now]++;
	}
}
void dfs(int x,int s)
{
	s+=sum[x];
	sum[x]=s;
//	s=sum[x];
	for(int i=1;i<=26;i++)
	{
		if(mp2[make_pair(x,i)]!=0)
		{
			dfs(mp2[make_pair(x,i)],s);
		}
	}
	for(int i=1;i<=26;i++)
	{
		if(mp3[make_pair(x,i)]!=0)
		{
			dfs(mp3[make_pair(x,i)],s);
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		cds[i]=s1[i].length();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		cdt[i]=t1[i].length();
		t1[i]=" "+t1[i];
		t2[i]=" "+t2[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cds[i];j++)
		{
			if(s1[i][j]!=s2[i][j])
			{
				ls[i]=j;
				s[i]=1;
				break;
			}
		}
		for(int j=cds[i];j>=1;j--)
		{
			if(s1[i][j]!=s2[i][j])
			{
				rs[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cdt[i];j++)
		{
			if(t1[i][j]!=t2[i][j])
			{
				lt[i]=j;
				break;
			}
		}
		for(int j=cdt[i];j>=1;j--)
		{
			if(t1[i][j]!=t2[i][j])
			{
				rt[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0)
		{
			continue;
		}
		long long c1=1,c2=1;
		for(int j=ls[i];j<=rs[i];j++)
		{
			hs11[i]=((long long)hs11[i]+(s1[i][j]-'a'+1)*(long long)c1%mod1)%mod1;
			hs12[i]=((long long)hs12[i]+(s1[i][j]-'a'+1)*(long long)c2%mod2)%mod2;
			hs21[i]=((long long)hs21[i]+(s2[i][j]-'a'+1)*(long long)c1%mod1)%mod1;
			hs22[i]=((long long)hs22[i]+(s2[i][j]-'a'+1)*(long long)c2%mod2)%mod2;
			c1=c1*31%mod1;
			c2=c2*31%mod1;
		}
		if(mp1[make_pair(make_pair(hs11[i],hs12[i]),make_pair(hs21[i],hs22[i]))]==0)
		{
			cnt++;
			mp1[make_pair(make_pair(hs11[i],hs12[i]),make_pair(hs21[i],hs22[i]))]=cnt;
			srt[i]=cnt;
		}
		else
		{
			srt[i]=mp1[make_pair(make_pair(hs11[i],hs12[i]),make_pair(hs21[i],hs22[i]))];
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long c1=1,c2=1;
		for(int j=lt[i];j<=rt[i];j++)
		{
			ht11[i]=((long long)ht11[i]+(t1[i][j]-'a'+1)*(long long)c1%mod1)%mod1;
			ht12[i]=((long long)ht12[i]+(t1[i][j]-'a'+1)*(long long)c2%mod2)%mod2;
			ht21[i]=((long long)ht21[i]+(t2[i][j]-'a'+1)*(long long)c1%mod1)%mod1;
			ht22[i]=((long long)ht22[i]+(t2[i][j]-'a'+1)*(long long)c2%mod2)%mod2;
			c1=c1*31%mod1;
			c2=c2*31%mod1;
		}
		if(mp1[make_pair(make_pair(ht11[i],ht12[i]),make_pair(ht21[i],ht22[i]))]==0)
		{
			cnt++;
			mp1[make_pair(make_pair(ht11[i],ht12[i]),make_pair(ht21[i],ht22[i]))]=cnt;
			trt[i]=cnt;
		}
		else
		{
			trt[i]=mp1[make_pair(make_pair(ht11[i],ht12[i]),make_pair(ht21[i],ht22[i]))];
		}
	}
	_=cnt;
	for(int i=1;i<=n;i++)
	{
		build(srt[i],i,0,0,srt[i],0,0,0,0,1,1);
	}
	for(int i=1;i<=_;i++)
	{
		dfs(i,0);
	}
	for(int i=1;i<=q;i++)
	{
		st1[0]=0;
		st2[0]=0;
		long long c1=1,c2=1,s1=0,s2=0;
		for(int j=rt[i]+1;j<=cdt[i];j++)
		{
			s1=(s1+(t1[i][j]-'a'+1)*c1%mod1)%mod1;
			s2=(s2+(t1[i][j]-'a'+1)*c2%mod2)%mod2;
			c1=c1*31%mod1;
			c2=c2*31%mod2;
			st1[j-rt[i]]=s1;
			st2[j-rt[i]]=s2;
		}
		c1=1,c2=1,s1=0,s2=0;
		int ans=0;
		int l=0,r=cdt[i]-rt[i];
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(mp4[make_pair(trt[i],make_pair(make_pair(s1,s2),make_pair(st1[mid],st2[mid])))]!=0)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		ans+=sum[mp4[make_pair(trt[i],make_pair(make_pair(s1,s2),make_pair(st1[l],st2[l])))]];
		for(int j=lt[i]-1;j>=1;j--)
		{
			
			int ss1=s1,ss2=s2;
			s1=(s1+(t1[i][j]-'a'+1)*c1%mod1)%mod1;
			s2=(s2+(t1[i][j]-'a'+1)*c2%mod2)%mod2;
			c1=c1*31%mod1;
			c2=c2*31%mod2;
			if(mp4[make_pair(trt[i],make_pair(make_pair(s1,s2),make_pair(0,0)))]==0)
			{
				break;
			}
			int l=0,r=cdt[i]-rt[i];
			while(l<r)
			{
				int mid=(l+r+1)/2;
				if(mp4[make_pair(trt[i],make_pair(make_pair(s1,s2),make_pair(st1[mid],st2[mid])))]!=0)
				{
					l=mid;
				}
				else
				{
					r=mid-1;
				}
			}
			ans+=sum[mp4[make_pair(trt[i],make_pair(make_pair(s1,s2),make_pair(st1[l],st2[l])))]];
			ans-=sum[mp4[make_pair(trt[i],make_pair(make_pair(ss1,ss2),make_pair(0,0)))]];
		}
		cout<<ans<<endl;
	}
}
