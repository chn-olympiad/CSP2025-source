#include <bits/stdc++.h>

using namespace std;

string s;
long long ans[10000005];
long long cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	for(long long i=0;i<len;i++){
		char as=s[i];
		if(as<='9'&&as>='0'){
			int ass=as-48;
			ans[cnt++]=ass;
		}
	}
	sort(ans,ans+cnt);
	for(long long i=cnt-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
