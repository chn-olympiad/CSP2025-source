#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int N=5e6+5;
const ull BASE=13331;
int n,q;
int ns[N],nt[N],ht[N][2],p[N],h1[N],h2[N];
string t[N][2];

ull getht(int l,int r,int id){
	if(l>r)
		return 0;
	return ht[r][id]-ht[l-1][id]*p[r-l+1];
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	int mx=-1e18;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ns[i]=s1.size();
		mx=max(mx,ns[i]);
		s1='#'+s1,s2='#'+s2;
		for(int j=1;j<=ns[i];j++)
			h1[i]=h1[i]*BASE+s1[j],h2[i]=h2[i]*BASE+s2[j];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size())
			continue;
		nt[i]=t[i][0].size();
		mx=max(mx,nt[i]);
		t[i][0]='#'+t[i][0],t[i][1]='#'+t[i][1];
	}
	p[0]=1;
	for(int i=1;i<=mx;i++)
		p[i]=p[i-1]*BASE;
	for(int i=1;i<=q;i++){
		if(t[i][0].size()!=t[i][1].size()){
			cout<<"0\n"; continue;
		}
		for(int j=1;j<=nt[i];j++)
			ht[j][0]=ht[j-1][0]*BASE+t[i][0][j],ht[j][1]=ht[j-1][1]*BASE+t[i][1][j];
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k+ns[j]-1<=nt[i];k++){
				int g0=getht(k,k+ns[j]-1,0),g1=getht(k,k+ns[j]-1,1);
				if(g0==h1[j]&&g1==h2[j]&&((getht(1,k-1,0)*p[ns[j]]+g1)*p[nt[i]-k-ns[j]+1]+getht(k+ns[j],nt[i],0)==getht(1,nt[i],1)))
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

