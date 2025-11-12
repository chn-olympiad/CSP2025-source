#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+50;
string s;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i] && s[i]<='9') 
			num[s[i]-'0']++;
	}
	for(int i=9;i>=0;){
		if(num[i]){
			cout<<i;
			num[i]--;
		}
		else i--;
	}
	return 0;
}
