#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])) a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}

