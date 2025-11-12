#include<bits/stdc++.h>
using namespace std;
int d[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(c>='0'&&c<='9'){
			d[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=d[i];j>=1;j--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
