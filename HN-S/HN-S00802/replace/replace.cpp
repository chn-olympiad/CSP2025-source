#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int n,m;
string s[500005],t[500005];
ull hs[500005][2],ht[500005][2];
const ull base=13331,basee=131;
ull pw[500005][2];
void init(string s,string t){
	for(int i=1;i<s.size();i++){
		ull x=(int)(s[i]-'a')*26+(t[i]-'a');
		hs[i][0]=hs[i-1][0]*base+x;
		hs[i][1]=hs[i-1][1]*basee+x;
//		cout<<i<<" ";
	}
}
ull getsum(int l,int r,int id){
	return hs[r][id]-hs[l-1][id]*pw[r-l+1][id];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0][0]=pw[0][1]=1;
	for(int i=1;i<=500000;i++)pw[i][0]=pw[i-1][0]*base,pw[i][1]=pw[i-1][1]*basee;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		for(int j=0;j<s[i].size();j++){
			ull x=(int)(s[i][j]-'a')*26+(t[i][j]-'a');
			ht[i][0]=ht[i][0]*base+x;
			ht[i][1]=ht[i][1]*basee+x;
		}//cout<<ht[i]<<'\n';
	}
	while(m--){
		string a,b;
		cin>>a>>b;
		int len=a.size();
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		a=" "+a,b=" "+b;
		init(a,b);
//		cout<<a<<" "<<b<<" "<<getsum(1,5)<<'\n';
		int l=0,r=0;
		for(int i=1;i<a.size();i++){
			if(a[i]!=b[i]){
				if(l==0)l=i;
				r=i;
			}
		}int ans=0;
		for(int i=1;i<=n;i++){
			int ll=max(1ll,r-(int)s[i].size()+1),rr=min(l,len-(int)s[i].size()+1);
			bool f=0;
//			cout<<ll<<" "<<rr<<'\n';
			for(int j=ll;j<=rr;j++){
				if(getsum(j,j+(int)s[i].size()-1,0)==ht[i][0]&&getsum(j,j+(int)s[i].size()-1,1)==ht[i][1]){
					f=1;
					break;
				}
			}ans+=f;
//			cout<<f<<"\n";
		}cout<<ans<<"\n";
	}
	return 0;
}
