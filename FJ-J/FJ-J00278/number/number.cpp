#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
int ans[10];
bool o(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(c>47&&c<58){
			ans[c-48]++;
		}
	}
	for(int i=9;i>-1;i--){
		while(ans[i]--){
			putchar(i+48);
		}
	}
}
