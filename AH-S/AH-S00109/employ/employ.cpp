#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
		int t;
		cin>>t;
	}
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
    return 0;
}






