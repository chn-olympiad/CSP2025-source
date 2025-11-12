#include<bits/stdc++.h>
using namespace std;
int a[15],L;
string s;
bool check(char x){
	return '0'<=int(x)&&int(x)<='9';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	L=s.size();
	for(int i=0;i<=L-1;i++){
		if(check(s[i])){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}
