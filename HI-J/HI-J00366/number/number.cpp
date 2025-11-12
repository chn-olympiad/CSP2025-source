#include<bits/stdc++.h>
using namespace std;
int a[13];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	string s,t;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
