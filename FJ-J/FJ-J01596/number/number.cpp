#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool b=false;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&b==false&&a[i]!=0){
			cout<<0;
			return 0;
		}
		while(a[i]){
			cout<<i;
			a[i]--;
			b=true;
		}
	}
	return 0;
} 
