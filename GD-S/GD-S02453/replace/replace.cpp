#include<bits/stdc++.h>
using namespace std;
long long n,p1=241,p2=347,p[1000010],mod=1000000919,q,l[1000010][5],h[1000010][5],ll[5],hh[1000010][5],cnt[200010],ans;
string s1[200010],s2[200010],t1,t2;
unordered_map<long long,long long> mp1;
unordered_map<long long,vector<long long> > mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	p[0]=1;
	for(long long i=1;i<=1000000;i++)
	{
		p[i]=p[i-1]*p1%mod*p2%mod;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		cnt[i]=1;
		long long num=0;
		for(long long j=0;j<s1[i].size();j++)
		{
			num=(num*p1%mod+s1[i][j])%mod;
		}
		for(long long j=0;j<s2[i].size();j++)
		{
			num=(num*p2%mod+s2[i][j])%mod;
		}
		if(mp1[num]>0)
		{
			cnt[mp1[num]]++;
			n--;
			i--;
		}
		else
		{
			mp1[num]=i;
		}
	}
	for(long long i=1;i<=n;i++)
	{
//		cin>>s1[i]>>s2[i];
//		cnt[i]=1;
		l[i][0]=s1[i].size();
		long long la=l[i][0];
		while(la>=1 && s1[i][la-1]==s2[i][la-1])
		{
			la--;
		}
		if(la==0) la=l[i][0];
//		cout<<la<<endl;
		for(long long j=1,now=1;j<=l[i][0];j++)
		{
			if(s1[i][j-1]!=s2[i][j-1] && now==1) now++;
			if(j>la && now==2) now++;
			l[i][now]++;
			h[i][now]=(h[i][now]*p1%mod+s1[i][j-1])%mod;
			h[i][now]=(h[i][now]*p2%mod+s2[i][j-1])%mod;
		}
//		if(i==349 || i==385)
//		{
//			cout<<i<<" "<<l[i][1]<<" "<<l[i][2]<<" "<<l[i][3]<<endl;
//			cout<<"::::::::"<<h[i][1]<<" "<<h[i][2]<<" "<<h[i][3]<<endl;
//		}
//		cout<<i<<" "<<l[i][1]<<" "<<l[i][2]<<" "<<l[i][3]<<endl;
//		cout<<"::::::::"<<h[i][1]<<" "<<h[i][2]<<" "<<h[i][3]<<endl;
		mp[h[i][2]].push_back(i);
	}
//	sort(mp[0].begin(),mp[0]);
//	long long qq=0;
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		ll[0]=t1.size();
		ll[1]=ll[2]=ll[3]=0;
//		bool fcuo=false;
		ans=0;
		long long la=ll[0];
		while(la>=1 && t1[la-1]==t2[la-1])
		{
			la--;
		}
		for(long long i=1,now=1;i<=ll[0];i++)
		{
			if(t1[i-1]!=t2[i-1] && now==1) now++,hh[i-1][2]=0;
			if(la!=0 && i>la && now==2) now++,hh[i-1][3]=0;
//			if(t1[i-1]!=t2[i-1] && now==3)
//			{
//				fcuo=true;
//				break;
//			}
			ll[now]++;
			hh[i][now]=(hh[i-1][now]*p1%mod+t1[i-1])%mod;
			hh[i][now]=(hh[i][now]*p2%mod+t2[i-1])%mod;
//			cout<<i<<" A "<<now<<" "<<hh[i][now]<<endl;
		}
		if(la==0)
		{
			long long xx;
//			cout<<"A\n";
			for(long long i:mp[0])
			{
//				cout<<i<<" "<<l[i][1]<<" "<<ll[0]<<endl;
				for(long long j=l[i][1];j<=ll[0];j++)
				{
					xx=(hh[j][1]-hh[j-l[i][1]][1]*p[l[i][1]]%mod+mod)%mod;
//					cout<<j<<" "<<xx<<" "<<h[i][1]<<endl;
					if(xx==h[i][1]) ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
//		if(fcuo)
//		{
//			cout<<"BB";
//			cout<<0<<"\n";
//			continue;
//		}
		long long x,y;
//		cout<<la<<endl;
//		cout<<ll[1]<<" "<<ll[2]<<" "<<ll[3]<<endl;
//		cout<<hh[ll[1]][1]<<" "<<hh[ll[1]+ll[2]][2]<<" "<<hh[ll[0]][3]<<endl;
		for(long long i:mp[hh[ll[1]+ll[2]][2]])
		{
			if(l[i][1]>ll[1] || l[i][3]>ll[3]) continue;
//		if(qq==102) cout<<i<<" "<<l[i][1]<<" "<<ll[1]<<" "<<l[i][3]<<" "<<ll[3]<<endl; 
//		if(qq==102) cout<<i<<" "<<x<<" "<<h[i][1]<<" "<<y<<" "<<h[i][3]<<"    "<<(x==h[i][1] && y==h[i][3])<<endl;
			x=(hh[ll[1]][1]-hh[ll[1]-l[i][1]][1]*p[l[i][1]]%mod+mod)%mod;
			y=(hh[ll[0]][3]-hh[ll[0]-l[i][3]][3]*p[l[i][3]]%mod+mod)%mod;
			if(x==h[i][1] && y==h[i][3]) ans+=cnt[i];
//			cout<<i<<" "<<x<<" "<<h[i][1]<<" "<<y<<" "<<h[i][3]<<endl;
		}
//		cout<<la<<" ";
//		qq++;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

6 2
axb cxd
axb cxd
axb cxd
aa bb
aa bb
aa bb
xaxbx xcxdx
aab bbb

2 1
ab ab
ba ba
ababab ababab

4 
xabc xbcd
abcx bcdx
abc bcd
xabcx xbcdx
xabcx xbcdx
xabcx xbcdx
xabcx xbcdx
xabcx xbcdx
*/
