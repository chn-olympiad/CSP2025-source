#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int te=int(s[i]);
		if(te>=48&&te<=57){
			a[te-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	return 0;
} 
