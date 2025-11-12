#include<bits/stdc++.h>
using namespace std;
long long p[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int y = s[i]-'0';
			p[y]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(long long j = 0;j < p[i];j++){
			cout<<i;
		}
	}
	return 0;
}
