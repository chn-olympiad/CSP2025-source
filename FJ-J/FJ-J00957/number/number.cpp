#include<bits/stdc++.h>
using namespace std;
string s;
long long ans[11];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>=48 and s[i]<=57){
			ans[s[i]-48]++;
		}
	}
	for(long long i=9;i>=0;i--){
		if(ans[i]>0){
			for(long long j=1;j<=ans[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
