#include<iostream>
#include<cstdio>
using namespace std;
string s;
int n[10];
int main(){
//	freopen("numder.in","r",stdin);
//	freopen("numder.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
			n[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(n[i]>0){
			for(int j=1;j<=n[i];j++)
				cout<<i;
		}
	}
	return 0;
} 
