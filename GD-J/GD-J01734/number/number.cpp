#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	int s[10]={};
	int k=0;
	for(int i=0;i<int(a.length());i++){
		if('0'<=a[i]&&a[i]<='9') s[a[i]-'0']++;
	}
	for(int i=9;i>=1;i--){
		for(int j=1;j<=s[i];j++){
			cout<<i;
		}
		k=k|s[i];
	}
	if(k==0) cout<<0;
	else{
		for(int j=1;j<=s[0];j++){
			cout<<0;
		}
	}
	return 0;
}
