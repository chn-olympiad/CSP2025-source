#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<=57&&s[i]>=48){
			a[s[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
