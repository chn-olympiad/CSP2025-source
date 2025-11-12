#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,a[100000001];
	cin>>s;
	int i=0;
	for(;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=int(s[i]);
		}
	}
	sort(a,a+i);
	for(int j=i;j>=1;j--) cout<<a[j];
	return 0;
} 