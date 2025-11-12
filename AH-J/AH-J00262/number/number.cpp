#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number,in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	getline(cin,s);
	int a[100010];int j=0;
	int b[15];
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]-'0'<10){
			a[j]=s[i]-'0';
			b[a[j]]++;
			j++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=1;k<=b[i];k++){
			cout<<i;
		}
	}
	
	return 0;
}
