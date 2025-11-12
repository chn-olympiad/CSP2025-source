#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q;string s[2][200050];
long long B=47,qpow[5000050],mod=998244853;
vector<long long>hx[2][200050];
void Work(int id) {
	hx[0][id].clear();hx[0][id].shrink_to_fit();
	hx[1][id].clear();hx[1][id].shrink_to_fit();
	int n=s[0][id].size();
	int nw=s[0][id][0]-'a'+1;
	hx[0][id].push_back(nw);
	
	for(int i=1;i<n;i++) {
		nw=s[0][id][i]-'a'+1+hx[0][id][i-1]*B%mod;
		nw=nw%mod;hx[0][id].push_back(nw);
	}
	nw=s[1][id][0]-'a'+1;
	hx[1][id].push_back(nw);
	
	for(int i=1;i<n;i++) {
		nw=s[1][id][i]-'a'+1+hx[1][id][i-1]*B%mod;
		nw=nw%mod;hx[1][id].push_back(nw);
	}
}

long long Myhash(int l,int r,int t,int id)
{if(l>r)return 0;if(r>=s[t][id].size())return 0;
if(l==0) return hx[t][id][r];return ((hx[t][id][r]-hx[t][id][l-1]*qpow[r-l+1]%mod)%mod+mod)%mod;}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	qpow[0]=1;
	for(int i=1;i<=5000000;i++) qpow[i]=qpow[i-1]*B%mod;
	cin>>n>>Q;
	for(int i=1;i<=n;i++) {
		cin>>s[0][i]>>s[1][i];
		Work(i);
	}
	while(Q--) {
		cin>>s[0][n+1]>>s[1][n+1];
		int len=s[0][n+1].size();Work(n+1);int ans=0;
		for(int i=0;i<len;i++) {
			for(int j=1;j<=n;j++) {
				if(i+s[0][j].size()-1>=len) continue;
				if(Myhash(i,i+s[0][j].size()-1,0,n+1)==Myhash(0,s[0][j].size()-1,0,j)) {
					long long nw=Myhash(0,i-1,0,n+1)*qpow[len-i]%mod+
					Myhash(0,s[0][j].size()-1,1,j)*qpow[len-i-s[0][j].size()]%mod+
					Myhash(i+s[0][j].size(),len-1,0,n+1);
					nw=nw%mod;
					
					long long to=Myhash(0,len-1,1,n+1);
					if(nw==to) {
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
