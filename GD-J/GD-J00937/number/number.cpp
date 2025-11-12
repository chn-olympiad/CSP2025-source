#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[20];
string s;
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&'0'<=s[i]){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
  //  fclose(stdin);
//	fclose(stdout);
	return 0;
}
