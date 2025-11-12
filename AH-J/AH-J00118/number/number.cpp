#include<bits/stdc++.h>
using namespace std;
long long cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			cnt[s[i]-'0']++;
		}
	}
	string num;
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			num+=(i+'0');
			cnt[i]--;
		}
	}
	cout<<num;
	return 0;
}
