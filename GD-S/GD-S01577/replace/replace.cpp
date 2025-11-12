#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int N=2e5+5,mod=1e9+7;

int n,q;
PII a[N],b[N];
LL h1[N],h2[N];
int base=31;
string t1,t2,s,s1,s2;
map<PII,bool> mp;

LL qp(LL x,LL y){
	LL res=1,i=x%mod;
	while(y){
		if(y&1) res=res*i%mod;
		i=i*i%mod;
		y>>=1;
	}
	return res;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	int slen1,slen2;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[i].second=s.length();
		for(int j=0;j<a[i].second;j++) a[i].first=(a[i].first*31%mod+s[j]-'a'+1)%mod;
		cin>>s;
		b[i].second=s.length();
		for(int j=0;j<b[i].second;j++) b[i].first=(b[i].first*31%mod+s[j]-'a'+1)%mod;
		if(a[i].first!=b[i].first) mp[{a[i].first,b[i].first}]=true;
	}
	while(q--){
		cin>>s1>>s2;
		slen1=s1.length();
		slen2=s2.length();
		if(slen1!=slen2) puts("0");
		else{
			h1[0]=s1[0]-'a'+1;
			h2[0]=s2[0]-'a'+1;
			for(int i=1;i<slen1;i++){
				h1[i]=(h1[i-1]*31%mod+s1[i]-'a'+1)%mod;
				h2[i]=(h2[i-1]*31%mod+s2[i]-'a'+1)%mod;
			}
			int l=0,r=slen1-1;
			while(s1[l]==s2[l]) l++;
			while(s1[r]==s2[r]) r--;
			LL ans=0;
			for(int i=r;i<slen1;i++){
				if(mp[{h1[i],h2[i]}]) ans++;
			}
			for(int i=0;i<l;i++){
				for(int j=r;j<slen1;j++){
					if(mp[{(h1[j]+mod-h1[i]*qp(31,j-i)%mod)%mod,(h2[j]+mod-h2[i]*qp(31,j-i)%mod)%mod}]) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
