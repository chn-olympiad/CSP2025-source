#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
using namespace std;
string s;
int k=0;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+0,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
