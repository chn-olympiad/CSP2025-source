#include<bits/stdc++.h>
using namespace std;

long long a[199],k=0;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=1;i--){
		if(a[i]>=1){
			k=1;
			break;
		}
	}
	if(k==0){
		k=0;
		cout<<k;
		return 0;
	}
	for(long long i=9;i>=0;i--){
		while(a[i]>=1){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
