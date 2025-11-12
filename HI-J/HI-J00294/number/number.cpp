#include <bits/stdc++.h>
using namespace std;
string s;
int a,b[1000],c[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len=s.length();
	for(int i=1;i<=len;i++){
		cin>>s;
		if(s[i]=0||s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9){
			a++;
			b[1000]=s[i];
			sort(b[1],b[a]);
			cout<<b[i];
		}
	}
	return 0;

}
