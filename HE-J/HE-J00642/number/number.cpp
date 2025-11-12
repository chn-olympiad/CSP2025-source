#include<bits/stdc++.h>
using namespace std;
char s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s >= 48 && s <= 57){
			a[s-'0']++;
		}
	}
	for(int i = 9;i >= 0; i--){
		for(int j = a[i];j > 0; j--){
			cout<<i;
		}
	}
	return 0;
}
