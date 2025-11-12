#include<bits/stdc++.h>
using namespace std;

string s;
int a[10],ans=0;


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	
	return 0;
} 
