#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000009],b[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	for(int i=1;i<=t;i++) b[a[i]]++;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++)cout<<i;
	}
	return 0;
} 
