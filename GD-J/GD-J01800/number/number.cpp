#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[11];
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(int(s[i]-48)>=0&&int(s[i]-48)<=9){
			a[int(s[i]-48)]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
