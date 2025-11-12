#include<bits/stdc++.h>
using namespace std;
int c=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[s.size()];
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	if(a[c-1]==0){
		cout<<"0";
		return 0;
	}
	for(int i=c-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
