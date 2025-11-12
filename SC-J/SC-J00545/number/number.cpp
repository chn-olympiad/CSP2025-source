#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10005]={},t=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t);
	if(a[t-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=t-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}