#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	string s;cin>>s;
	for(ll i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[int(s[i]-'0')]++;
		}
	}
	//cout<<num[9]<<endl;
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}
