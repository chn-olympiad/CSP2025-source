//输入的字符串不知道为什么会缩水，长度最多只能到4095，不过代码应该没有问题^-^
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	//cout<<"\n";
	//cout<<s;
	//这里输出的字符串明显比输入的短
	for(ll i=0;i<(ll)s.size();i++){
		if(isdigit(s[i])){
			cnt[s[i]-'0']++;
		}
	}
	ll flag=0;
	for(ll i=9;i>=1;i--){
		if(i==0&&cnt[0]&&flag==0){
			cout<<0;
		}else{
			flag=1;
			for(ll j=1;j<=cnt[i];j++){
				cout<<i;
			}
		}
	}
	//cout<<s.size();
	//这里输出最多只有4095
	return 0;
}
