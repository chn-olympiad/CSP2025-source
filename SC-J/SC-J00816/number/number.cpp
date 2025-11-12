#include<bits/stdc++.h>
using namespace std;

string s;
int a[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9'){
			a[i-'0']++;
		}
	}for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
} 