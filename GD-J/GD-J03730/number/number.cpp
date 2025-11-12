#include<bits/stdc++.h>
using namespace std;
string s;
int n[12];
int ans,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int x=s.length();
	for(int i=0;i<x;i++){
		if(isdigit(s[i])){
			a=s[i]-'0';
			n[a]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(n[i]){
			for(int j=1;j<=n[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
	fclose(stdin);fclose(stdout);
}
