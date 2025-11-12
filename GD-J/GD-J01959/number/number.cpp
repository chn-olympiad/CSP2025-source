#include<iostream>
#define int long long
using namespace std;
string s;
int num[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++) if(s[i]>='0'&&s[i]<='9') num[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(num[i]--){
			cout<<i;
		}
	}
	return 0;
}
