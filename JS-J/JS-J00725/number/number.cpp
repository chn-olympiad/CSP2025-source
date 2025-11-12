#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[(int)s[i]-48]++;
		}
	}
	bool flag=false;
	for(int i=1;i<=9;i++){
		if(cnt[i]){
			flag=true;
			break;
		}
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
}
