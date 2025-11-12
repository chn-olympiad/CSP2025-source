#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int mod=998244353;
const int mod2=1e9+7;
const int mod3=1e9+9;
const long long MAA=LONG_LONG_MAX;
string a,b;
int l[maxn],r[maxn],ll,rr,tmp;
long long cnt1[maxn],cnt2[maxn],cnt3[maxn],cnt4[maxn];
typedef tuple<long long,long long,int,int,long long,long long> tii;
tii str[maxn];
vector<long long>x,y;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	x.resize(maxn),y.resize(maxn);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=0;j<a.length();j++)if(a[j]!=b[j]){l[i]=j;break;}
		for(int j=a.length()-1;j>=0;j--)if(a[j]!=b[j]){r[i]=j;break;}
		for(int j=l[i];j<=r[i];j++)cnt3[i]=(cnt3[i]*26+a[j]-'a'+1)%mod2;
		for(int j=l[i];j<=r[i];j++)cnt4[i]=(cnt4[i]*26+b[j]-'a'+1)%mod2;
		for(int j=l[i]-1;j>=0;j--)cnt1[i]=(cnt1[i]*26+a[j]-'a'+1)%mod;
		for(int j=r[i]+1;j<a.length();j++)cnt2[i]=(cnt2[i]*26+a[j]-'a'+1)%mod;
		str[i]=make_tuple(cnt3[i],cnt4[i],-l[i],-(a.length()-r[i]-1),cnt1[i],cnt2[i]);
//		cerr<<cnt3[i]<<' '<<cnt4[i]<<' '<<l[i]<<' '<<a.length()-r[i]-1<<' '<<cnt1[i]<<' '<<cnt2[i]<<'\n';
	}
	sort(str+1,str+n+1);
	for(int i=1;i<=q;i++)
	{
		x.clear(),y.clear();
		cin>>a>>b;
		if(a.length()!=b.length()){cout<<0<<'\n';continue;}
		for(int j=0;j<a.length();j++)if(a[j]!=b[j]){ll=j;break;}
		for(int j=a.length()-1;j>=0;j--)if(a[j]!=b[j]){rr=j;break;}
		for(int j=ll-1;j>=0;j--)x[ll-j]=(x[ll-j-1]*26+a[j]-'a'+1)%mod;
		for(int j=rr+1;j<a.length();j++)y[j-rr]=(y[j-rr-1]*26+a[j]-'a'+1)%mod;
		int cntt1=0,cntt2=0,cntt3=0;
		for(int j=ll;j<=rr;j++)cntt1=(cntt1*26+a[j]-'a'+1)%mod2;
		for(int j=ll;j<=rr;j++)cntt2=(cntt2*26+b[j]-'a'+1)%mod2;
		int l1=lower_bound(str+1,str+n+1,make_tuple(cntt1,cntt2,0,0,0,0))-str-1;
		int r1=upper_bound(str+1,str+n+1,make_tuple(cntt1,cntt2,MAA,MAA,MAA,MAA))-str-2;
//		cerr<<l1<<' '<<r1<<'\n';
		for(int j=l1;j<=r1;j++)
		{
			int l2=-get<2>(str[j]),r2=-get<3>(str[j]);
//			cerr<<l2<<' '<<r2<<'\n';
			if(ll>=l2&&get<4>(str[j])==x[l2]&&rr>=r2&&get<5>(str[j])==y[r2])++cntt3;
//			cerr<<get<4>(str[j])<<' '<<x[l2]<<' '<<get<5>(str[j])<<' '<<y[r2]<<'\n';
		}
		cout<<cntt3<<'\n';
	}
	return 0;
}