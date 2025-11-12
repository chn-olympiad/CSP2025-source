#include <bits/stdc++.h>
using namespace std;
string s;
long long t[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]!=0){
			t[i]--;
			cout<<i;
		}
	}
	return 0;
}
