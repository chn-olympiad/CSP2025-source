#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
