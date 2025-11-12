#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
int Time=clock();
bool mst;
const int N=1005;
const ull x=251;
int n,q,len[N];
ull st[N],ed[N],d[2*N];
ull qpow(ull a,ull b){
	ull ans=1ll;
	while(b){
		if(b&1ull)  ans=ans*a;
		a=a*a,b>>=1;
	}
	return ans;
}
ull gethash(int a,int b){
	if(a>b)  return 0;
	return d[b]-d[a-1]*qpow(x,b-a+1);
}
bool med;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		len[i]=s1.size(),s1=' '+s1,s2=' '+s2;
		for(int j=1;j<=len[i];j++)
			st[i]=st[i]*x+s1[j]-'a',ed[i]=ed[i]*x+s2[j]-'a';
	}
	while(q--){
		cin>>s1>>s2;
		int l=s1.size(),ans=0;
		ull td=0ll;
		s1=' '+s1,s2=' '+s2;
		for(int i=1;i<=l;i++)
			d[i]=d[i-1]*x+s1[i]-'a',td=td*x+s2[i]-'a';
		for(int i=1;i<=n;i++)
			for(int j=1;j+len[i]-1<=l;j++){
				if(gethash(j,j+len[i]-1)!=st[i])  continue;
				int l2=len[i],l3=l-(j+len[i]-1);
				if(gethash(1,j-1)*qpow(x,l2+l3)+ed[i]*qpow(x,l3)+gethash(j+len[i],l)==td)  ans++;
			}
		cout<<ans<<'\n';
	}
	// cerr<<"Time:"<<1.0*(clock()-Time)/CLOCKS_PER_SEC<<"s\n";
	// cerr<<"Memory:"<<1.0*(&med-&mst)/1024.0/1024.0<<"MB\n";
	return 0;
}