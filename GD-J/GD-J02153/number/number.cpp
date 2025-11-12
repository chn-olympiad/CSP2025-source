#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100001]={};
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n+1);
	for(int i=n;i>0;i--){
		cout<<a[i];
	}
} 
