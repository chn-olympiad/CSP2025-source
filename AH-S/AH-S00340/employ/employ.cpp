#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int r[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	bool bz=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			bz=1;
		}
	}
	if(bz==0){
		int cnt=0,uncnt=0;
		for(int i=1;i<=n;i++){
			if(r[i]>uncnt){
				cnt++;
			}else{
				uncnt++;
			}
		}
		cout<<cnt<<endl;
		long long ans=1;
		if(cnt<m){
			cout<<0<<endl;
			return 0;
		}
		for(int i=1;i<=cnt;i++){
			ans=ans*i%MOD;
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
