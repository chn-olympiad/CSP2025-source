#include<bits/stdc++.h>
using namespace std;
int a[1000],c=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			while(a[i]){
				cout<<i;
				a[i]--;
			}
		}
	}
	return 0;
} 
