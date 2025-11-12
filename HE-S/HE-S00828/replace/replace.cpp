#include<bits/stdc++.h>
#define int long long
using namespace std;
#define ull unsigned long long

vector<signed> v;
const signed LEN=5e6+5;

const signed N=2e5+5;
signed n,q;
// bool vis[N];
string s1,s2;
string t1,t2;

const ull prime=131;
ull h1[LEN],h2[LEN],ksm[LEN];
unordered_map<signed,bool> lenn;
unordered_map<ull,signed> mp1;
unordered_map<ull,signed> mp2[N];
int tot;

ull dohash(const string &s)
{
	ull nw=0;
	for(int i=0;i<s.size();i++) (nw*=prime)+=s[i];
	// for(int i=0;i<s.size();i++)nw=nw*prime+s[i];
	return nw;
}

void solve()
{
	cin>>t1>>t2;

	for(int i=1;i<=t1.size();i++)
	h1[i]=h1[i-1]*prime+t1[i-1];

	for(int i=1;i<=t2.size();i++)
	h2[i]=h2[i-1]*prime+t2[i-1];

	int L=1,R=t1.size();
	while(t1[L-1]==t2[L-1]) L++;
	while(t1[R-1]==t2[R-1]) R--;
	int nwlen=R-L+1;
	int l=0;
	while(l<v.size()&&v[l]<nwlen) l++;
	long long ans=0;
	for(int i=R;i<=t1.size();i++)
	{
		if(l<v.size()&&v[l]<nwlen) l++;
		// cout<<l<<" "<<v[l]<<"\n";
		for(int j=l;j<v.size()&&v[j]<=i;j++)
		{
			// cout<<'a';
			ull nw=(h1[i]-h1[i-v[j]]*ksm[v[j]]);
			if(mp1.count(nw))
			{			
				ull nw2=(h2[i]-h2[i-v[j]]*ksm[v[j]]);
				if(mp2[mp1[nw]].count(nw2)) ans+=mp2[mp1[nw]][nw2];
			}
		}
		nwlen++;
	}
	cout<<ans;
	// cout<<"\n";
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ksm[0]=1;
	for(int i=1;i<LEN;i++) ksm[i]=ksm[i-1]*prime;

	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		// if(s[i][1].size()==0) cout<<"hboufubgbu;gub;ga";
		if(!lenn[s1.size()]) lenn[s1.size()]=1,v.push_back(s1.size());
		ull aaa=dohash(s1);
		ull bbb=dohash(s2);
		if(!mp1.count(aaa)) mp1[aaa]=++tot;
		mp2[mp1[aaa]][bbb]++;
	}
	sort(v.begin(),v.end());
	// sizv=v.size();
	// for(int i:v) cout<<i<<" ";
	// cout<<"\n";
	// cout<<v.size()<<"\n";
	for(int i=1;i<q;i++) solve(),cout<<"\n";
	solve();
	// fflush(stdout);
	cout<<endl;
	return 0;
}