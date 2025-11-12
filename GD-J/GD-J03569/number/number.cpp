#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("number.in","w", stdin);
	freopen("number.out","r", stdout);
	string s;
	cin>>s;
	int k=1;
	int a[100001];
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')>=0 and (s[i]-'0')<=9){
			a[i]=s[i];
			k++;
		}
	}
	sort(a,a+k);
	while(k){
		cout<<s; 
		k--;
	}
	return 0;
} 
