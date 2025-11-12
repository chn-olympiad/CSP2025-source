#include <bits/stdc++.h>
using namespace std;
int n[114]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0' and s[i]<='9'){
			n[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<n[i];j++){
			cout<<i;
		}
	}
	return 0;
}
