#include <bits/stdc++.h>
using namespace std;
int a[1000010],len=0;

void solve(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//#Shang4Shan3Ruo6Shui4
	solve();
	return 0;
}
