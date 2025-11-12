#include <bits/stdc++.h>
using namespace std;
int nd[510];
int nx[510];
int pl[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++){
		nd[i+1]=s[i]-'0';
	}
	for (int i=1;i<=n;i++) cin>>nx[i];
	for (int i=1;i<=n;i++) pl[i]=i;
	long long ans=0;
	do{
		int cnt=0;
		int giveup=0;
		for (int i=1;i<=n;i++){
			if (giveup>=nx[pl[i]]){
				giveup++;
				continue;
			}if (nd[i]==0){
				giveup++;
			}else{
				cnt++;
			}
		}
		if (cnt>=m) ans++;
	}while(next_permutation(pl+1,pl+n+1));
	cout<<ans%998244353<<endl;
	return 0;
}
