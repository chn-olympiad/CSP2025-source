#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> n(15,0);
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int p=s[i]-'0';
			n[p]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<n[i];j++){
			cout<<i;
		}
	}
	return 0;
}
