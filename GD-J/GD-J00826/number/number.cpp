#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		int x=s[i]-'0';
		if(0<=x&&x<=9){
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			a[i]--;
			cout<<i;
		}
	}
} 
