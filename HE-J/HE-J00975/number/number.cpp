#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000];
	int n,a[1000];
	while(s[n]!='\n'){
		cin>>s[n];
		n++;
		break;
	}
	
	for(int i=0;i<n;i++){
		if(s[i]>='0'and s[i]<='9')
		a[i]=s[i];
		else
		continue;
	}
	
	for(int i=0;i<n;i++){
		cout<<s[i];
	}
	return 0;
} 
