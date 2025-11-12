#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000005];
int j=0;
long long ans;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
