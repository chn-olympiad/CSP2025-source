#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5;
const ll base=255;
const ll mod=1e9+7;
int n,q;
string s1[N+5],s2[N+5];
string t1,t2;
int dis[N+5];
map<int,vector<pair<int,int>>> mp;
ll hash1[N+5],hash2[N+5];
ll hasha[N+5],hashb[N+5];

ll FastPow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

ll geta(int l,int r){
	return (hasha[r]-hasha[l-1]*FastPow(base,r-l+1)%mod+mod)%mod;
}

ll getb(int l,int r){
	return (hashb[r]-hashb[l-1]*FastPow(base,r-l+1)%mod+mod)%mod;
}

bool check(string a,string b,ll ha,ll hb,ll len){
	int n=a.size();
	for(int i=0;i<n;i++){
		hasha[i+1]=(hasha[i]*base+a[i])%mod;
		hashb[i+1]=(hashb[i]*base+b[i])%mod;
		if(i+1>=len){
			if(geta(i-len+2,i+1)==ha&&getb(i-len+2,i+1)==hb&&geta(1,i-len+1)==getb(1,i-len+1)&&geta(i+2,n)==getb(i+2,n))
				return 1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int cnta=0,cntb=0;
		int n=s1[i].size();
		for(int j=0;j<n;j++){
			hash1[i]=(hash1[i]*base+s1[i][j])%mod;
			hash2[i]=(hash2[i]*base+s2[i][j])%mod;
			cnta+=(s1[i][j]=='a'),cntb+=(s1[i][j]=='b');
		}
		if(cnta!=n-1||cntb!=1)
			flag=1;
		int j1,j2;
		for(j1=0;j1<n;j1++)
			if(s1[i][j1]=='b')
				break;
		for(j2=0;j2<n;j2++)
			if(s2[i][j2]=='b')
				break;
		dis[i]=j2-j1;
		mp[dis[i]].push_back(make_pair(j1,n-j1));
	}
	if(!flag){
		while(q--){
			cin>>t1>>t2;
			int n=t1.size();
			int j1,j2;
			for(j1=0;j1<n;j1++)
				if(t1[j1]=='b')
					break;
			for(j2=0;j2<n;j2++)
				if(t2[j2]=='b')
					break;
			vector<pair<int,int>> range=mp[j2-j1];
			int cnt=0;
			for(int i=0;i<range.size();i++){
				// cout<<"srange:["<<range[i].first<<","<<range[i].second<<"] trange:["<<j1<<","<<n-j1<<"]\n";
				if(range[i].first<=j1&&range[i].second<=(n-j1))
					++cnt;
			}
			cout<<cnt<<"\n";
		}
	}
	else{
		while(q--){
			cin>>t1>>t2;
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(check(t1,t2,hash1[i],hash2[i],s1[i].size())){
					// cout<<"same with "<<i<<"\n";
					++cnt;
				}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}