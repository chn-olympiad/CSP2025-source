#include<bits/stdc++.h>
using namespace std;

const int N=5e5+9;
int n,m,c[N],a[N],ans;
string s;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s='0'+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) a[i]=i;
	do{
		int ts=0;
		int rejected=0;
		for(int i=1;i<=n;i++){
			//cout<<'@'<<a[i]<<' '<<c[a[i]]<<' '<<s[a[i]]<<'\n';
			if(s[i]=='0'||rejected>=c[a[i]]){
				rejected++;
			}
			else{
				ts++;
			}
			//cout<<'@'<<a[i]<<' '<<rejected<<'\n';
		}
		if(ts>=m) ans++;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
	return 0;
}
