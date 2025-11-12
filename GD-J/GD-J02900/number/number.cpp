#include<bits/stdc++.h>
using namespace std;
int number[1000010];
int len;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int sint=int(s[i]);
		if(sint>=48 && sint<=57){
			number[++len]=s[i]-'0';
		}
	}
	sort(number+1,number+1+len);
	for(int i=len;i>=1;i--){
		cout<<number[i];
	}
	return 0;
}
// 48 57
