#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=1;k<=a[i];k++){
			cout<<i;
		}
	}
	return 0;
} 
