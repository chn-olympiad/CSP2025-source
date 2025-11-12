#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int c[100];
	memset(c,0,sizeof(c));
	for(long long i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[int(s[i]-'0')]++;
		}
	}
	for(long long i = 9;i>=0;i--){
		if(c[i]>0){
			for(long long j = 1;j<=c[i];j++){
				cout << i;
			}
		}
	}
	return 0;
}
