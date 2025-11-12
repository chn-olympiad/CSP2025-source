#include<bits/stdc++.h>
using namespace std;

int t[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens = s.size();
	for(int i=0;i<=15;i++){
		t[i] = 0;
	}
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[(int)s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
} 