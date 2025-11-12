#include <bits/stdc++.h>
using namespace std;
string s;
int l,w=1,ans[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			ans[w]=s[i]-'0';
//			cout<<ans[w]<<endl;
			w++;
		}
	}
	w--;
	sort(ans+1,ans+1+w);
	for(int i=w;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
