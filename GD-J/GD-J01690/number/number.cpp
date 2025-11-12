#include<bits/stdc++.h>
using namespace std;
long long num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		if(num[i]){
			while(num[i]--)cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
