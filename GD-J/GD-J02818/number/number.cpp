#include<bits/stdc++.h>
using namespace std;
const int M=2*10e7;
long long ans[M];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string  s;
	getline(cin,s);
	int cnt=1;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(ans,ans+cnt);
	for(int i=cnt-1;i>0;i--){
		cout<<ans[i];
	}
	return 0;
}

