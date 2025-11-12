#include<bits/stdc++.h>
using namespace std;
#define FILE "replace"
constexpr int base=1145141;
unsigned long long hashs[2000005][2];
unsigned long long h2[100005][2];
int sz[100005];
unsigned long long pw[2000005];
int n,q;
string tmp,t2;
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	pw[0]=1;
	for(int i=1;i<=2000001;i++){
		pw[i]=pw[i-1]*base;
	}
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> tmp;
		sz[i]=tmp.size();
//		cout << "sz[i=" << i << "]=" << sz[i] << ".\n";
		tmp=" "+tmp;
		
		for(int j=1;j<=sz[i];j++){
			h2[i][0]=h2[i][0]*base+tmp[j];
		}
		cin >> tmp;
		tmp=" "+tmp;
		for(int j=1;j<=sz[i];j++){
			h2[i][1]=h2[i][1]*base+tmp[j];
		}
//		cout << "before hash=" << h2[i][0] << ", after hash=" << h2[i][1] << ".\n";
	}
	while(q--){
		cin >> tmp >> t2;
		int siz=tmp.size();
		tmp=" "+tmp,t2=" "+t2;
		for(int i=1;i<=siz;i++){
			hashs[i][0]=hashs[i-1][0]*base+tmp[i];
		}
		for(int i=1;i<=siz;i++){
			hashs[i][1]=hashs[i-1][1]*base+t2[i];
		}
		int bak=siz;
		while(bak>1 && tmp[bak]==t2[bak])	--bak;
		int ans=0;
		for(int i=1;i<=siz;i++){
			
			for(int j=1;j<=n;j++){
				if(i+sz[j]-1>siz || i+sz[j]-1<bak)	continue;
				int l=i-1,r=i+sz[j]-1;
//				cout << "before hash=" << hashs[r][0]-pw[r-l]*hashs[l][0] << ", after hash=" << hashs[r][1]-pw[r-l]*hashs[l][1] << ".\n";
				if(hashs[r][0]-pw[r-l]*hashs[l][0]==h2[j][0] && hashs[r][1]-pw[r-l]*hashs[l][1]==h2[j][1]){
					++ans;
				}
			}
			if(tmp[i]!=t2[i])	break;
		}
		cout << ans << '\n';
	}
	return 0;
}

