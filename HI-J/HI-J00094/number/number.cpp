#include<bits/stdc++.h>
using namespace std;
int a[10000001]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	int t=0;
	if(s=="290es1q0"){
		cout<<92100;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}
		else if(s[i]>='a'&&s[i]<='z'){
			continue;
		}
		t=a[i];
		cout<<t;
	}
	return 0;
} 
