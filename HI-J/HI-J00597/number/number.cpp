#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int max=-1,a[100001],sum=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9'&&s[i]>max) max=s[i];
	} 
	for(int j=0;j<=9;j++){
		for(int i=0;i<s.size();i++){
		if(s[i]==max){
			cout<<s[i];
			}
		}
		max=max-1;
	}
	
	return 0;
} 
