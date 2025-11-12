#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int main(){
	char s[N];
    char a[N];
	cin>>s;
	if(s[0]<='9'&&s[0]>='0'){
		if(s[1]>='A'&&s[1]<='z'&&a[1]>='a'&&a[1]<='z'&&s[1]<='9'&&s[1]>='0')int f=0;	
		else{
		cout<<s[0];
		return 0;
		}
	}
	for(int i=1;i<=N;i++){
		if(s[i]<='9'||s[i]>='0') a[i]=s[i];
	}
	for(int i=1;i<=N;i++){
		int n=0;
		if(a[i]<a[i+1]) n=a[i];a[i+1]=n;a[i]=a[i+1];
	}
	cout<<a;
	return 0;
} 
