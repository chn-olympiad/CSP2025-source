#include<bits/stdc++.h>
#define psb push_back
using namespace std;
const int N=2e5+10,M=5e6+10;
const int base=1331,mod=1e9+9;
string s[N][2],s1[2];
int ha[M][2],h[2][M],pw[M];
int n,m;
unordered_map<int,int>A,B;
unordered_map<int,vector<int> >D;
set<int>C;
inline int ask(int l,int r,int id){
	int len=r-l+1;
	return (h[id][r]-1ll*h[id][l-1]*pw[len]%mod+mod)%mod;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			cin>>s[i][j];
			int len=s[i][j].size();
			int res=0;
			for(int k=0;k<len;k++)
				res=1ll*res*base%mod+s[i][j][k]-'a'+1;
			res=res%mod;
			if(!j)A[res]++;
			else  B[res]++;
			ha[i][j]=res;
			C.insert(len);
		}
	//	cout<<ha[i][0]<<" "<<ha[i][1]<<"\n";
		D[ha[i][0]].psb(ha[i][1]);
	}
//	for(int v:C)
//		cout<<v<<"\n";
	for(int i=1;i<=m;i++){
		cin>>s1[0]>>s1[1];
		s1[0]=' '+s1[0];
		s1[1]=' '+s1[1];
		int l=n,r=1;
		int len=s1[0].size();
		for(int j=1;j<=len;j++)
			if(s1[0][j]!=s1[1][j]){
				l=j;
				break;
			}
		for(int j=len;j>=1;j--)
			if(s1[0][j]!=s1[1][j]){
				r=j;
				break;
			}
		if(s1[0].size()!=s1[1].size()){
			cout<<0<<"\n";
			continue;
		}
		for(int j=0;j<2;j++)
			for(int k=1;k<=len;k++)
				h[j][k]=1ll*h[j][k-1]*base%mod+s1[j][k]-'a'+1,h[j][k]%=mod;
	//	cout<<l<<" "<<r<<"            len\n";
	//	cout<<h[0][len]<<" "<<h[1][len]<<"         ha\n";
		set<int>::iterator it=C.lower_bound(r-l+1);
		int ans=0;
		for(;it!=C.end();it++){
			if(*it>len)
				break;
			int L=max(1,r-*it+1);
			int R=min(len-*it+1,l);
		//	cout<<*it<<" "<<L<<" "<<R<<"     check\n";
			int ll=*it;
			for(int j=L;j<=R;j++){
				if(!A[ask(j,j+ll-1,0)])
					continue;
				if(!B[ask(j,j+ll-1,1)])
					continue;
				int p=ask(j,j+ll-1,0),q=ask(j,j+ll-1,1);
				for(int v:D[p]){
					if(v==q)
						ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL);
	pw[0]=1;
	for(int i=1;i<N;i++)
		pw[i]=1ll*pw[i-1]*base%mod;
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
} 
