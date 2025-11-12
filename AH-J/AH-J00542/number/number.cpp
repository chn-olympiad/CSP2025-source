#include <bits/stdc++.h>
using namespace std;
string str;
int b[15]={0};
signed main(){
	freopen("number.in","r",sidin);
	freopen("number.out","w",stdout);
	cin>>str;
	long long len=str.size();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			b[str[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		while(b[i]--){
			cout<<i;
		}
	}
	return 0;
}
