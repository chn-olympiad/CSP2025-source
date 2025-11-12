#include<bits/stdc++.h>
using namespace std;
string s;
long long num_times[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<(long long)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num_times[(long long)s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<num_times[i];j++){
			cout<<i;
		}
	}
	return 0;
}
