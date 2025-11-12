#include<bits/stdc++.h>
#define int long long 
const int mod=998244353;
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int> c(n+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	vector<int> tmp(n+1);
	for(int i=1;i<=n;i++)tmp[i]=i;
	int ans=0;
	do{
		int cnt=0,can=0;
		for(int i=1;i<=n;i++){
//			cout<<tmp[i]<<" \n"[i==n];
			if(s[i-1]=='1'&&cnt<c[tmp[i]]){
				can++;
			}else {
				cnt++;
			}
		}
		if(can>=m)ans++,ans%=mod;
	}while(next_permutation(tmp.begin()+1,tmp.end()));
	cout<<ans<<"\n";
	return 0;
}
