#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6+10;
string s;
int t[15];
void solve(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	bool b=1;
	for(int i=9;i>=0;i--){
		if(i==0&&b){
			cout<<0;break;
		}
		while(t[i]--){
			b=0;cout<<i;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int _=1;//cin>>_;
	while(_--)solve();
}
//#Shang4Shan3Ruo6Shui4
