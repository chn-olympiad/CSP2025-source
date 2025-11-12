#include <bits/stdc++.h> 
using namespace std;


char nu[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int pos=0;
	string s;cin >> s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nu[++pos] = s[i];
		}
	}
	sort(nu+1,nu+pos+1);
	for(int i = pos;i>=1;i--){
		cout << nu[i];
	}
	return 0;
}
