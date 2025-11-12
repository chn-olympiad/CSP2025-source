#include <bits/stdc++.h>
using namespace std;
string s;
int i,j,g,n,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++){
		s[i]=s[i]-'0';
		for(j=0;j<=9;j++){
			if(s[i]==j){
				cout<<j;
			}
		}
	}
	
	return 0;
}
