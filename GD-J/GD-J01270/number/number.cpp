#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number3.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100];
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--; 
		}
	}
}
