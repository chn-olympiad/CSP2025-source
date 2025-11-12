#include<bits/stdc++.h>
using namespace std;
int has[10];
string s;
int main(){
	//我要上洛谷抽象代码大赏 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9')has[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<has[i];j++){
			cout<<i;
		}
	} 
	return 0;
}
