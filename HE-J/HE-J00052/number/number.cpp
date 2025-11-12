#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
int a[10];
bool num(char c){
	return ((c>='0')&&(c<='9'));
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(num(str[i])){
			a[str[i]-'0']++;
		}
	}
	for(int i=9;i>-1;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
