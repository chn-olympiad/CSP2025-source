#include<bits/stdc++.h>
using namespace std;
string s;
char a;
char b[10000];
int d[10000];
int c;
int ans;
int main(){
	cin>>s;
	for(int i=1;i<=s.size();i++){
			a=s[i];
			b[i]=a;	
			cout<<b[i];
	}
	for(int i=1;i<=s.size();i++){
		if(b[i]>='49'&&b[i]<='57'){
			c=b[i];
			for(int j=1;j<=s.size();j++){
				d[j]=c;
			}
		}
	}
	for(int i=1;i<=s.size();i++){
		cout<<b[i];
	}
	return 0;
}
