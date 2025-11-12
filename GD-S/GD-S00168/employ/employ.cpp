#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,c[510],a[510],ans,an;
string s;
bool f[510],ff;
void plApd(int x){
	if(x>n){
		int ly=0,wly=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') wly++;
			if(s[i]=='1'){
				if(a[i]<=wly) wly++;
				else ly++;
			}
		}
		if(ly>=m) ans=(ans+1)%N;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			a[x]=c[i];
			f[i]=1;
			plApd(x+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	plApd(1);
	cout<<ans;
	return 0;
}

