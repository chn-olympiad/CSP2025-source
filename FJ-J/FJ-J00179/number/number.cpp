#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n[10]={0},a;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a=s[i];
			n[a-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++)cout<<i;
	}
	
	return 0;
} 
