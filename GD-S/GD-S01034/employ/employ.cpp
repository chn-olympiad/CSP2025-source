#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505; 
int n,m,a[N],ans,c[N],p[N];
void solve(){
	int sum=0,lu=0;
	for(int i=1;i<=n;i++){
		if(sum>=c[p[i]]){
		    sum++;
		    continue;
		}
		if(a[i]==0){
			sum++;
		}else{
			lu++;
		}
	}
	if(lu>=m){
		ans++;
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<' ';
//		}cout<<'\n';
		ans%=mod;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	string s;cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
//    for(int i=1;i<=n;i++){
//    	cout<<a[i]<<' ';
//	}cout<<'\n';
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	do{
		solve();
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<' ';
//		}cout<<'\n';
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<'\n';
	return 0;
} 
