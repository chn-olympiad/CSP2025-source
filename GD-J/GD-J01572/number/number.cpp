#include<bits/stdc++.h>
using namespace std;
string s; 
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i < s.length();i++){
		int ix = s[i] - '0';
		if(ix >= 0 && ix <= 9){
			a[ix]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 
