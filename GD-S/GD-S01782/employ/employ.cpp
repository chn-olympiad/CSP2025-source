#include <bits/stdc++.h>
using namespace std;
const int N=523,Mod=998244353;
int n,m,c[N],a[N];
char s[N]; 

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i) cin>>c[i];
	for(int i=1;i<=n;++i) a[i]=i;
	int ans=0;
	do{
		int t=0,res=0;
		for(int i=1;i<=n;++i){
			if(t>=c[a[i]]) {
				++t;
				continue;
			}
			if(s[i]=='1') ++res;
			else ++t;
		}
		ans+=(res>=m);
		ans%=Mod;
	}while(next_permutation(a+1,a+n+1)); 
	cout<<(ans%Mod+Mod)%Mod;
	return 0;
}
