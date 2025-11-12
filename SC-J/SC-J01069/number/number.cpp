#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[10];
int main(){
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	for(int i=1;i<=cnt;i++){
		b[a[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++) cout<<i;
	}
	return 0;
}