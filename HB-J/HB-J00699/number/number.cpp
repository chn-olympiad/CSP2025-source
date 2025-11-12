#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
char a[N],s[N];

int main(){
freopen("number.in","r",stdin);
freopen("number.ans","w",stdout);
cin>>s[N];
	for(int i=0;i<=s[N];i++){
		if(i==9)
		cout<<s[i];
		else if(i==8)
		cout<<s[i+1];
		else if(i==7)
		cout<<s[i+2];
		else if(i==6)
		cout<<s[i+3];
		else if(i==5)
		cout<<s[i+4];
		else if(i==4)
		cout<<s[i+5];
		else if(i==3)
		cout<<s[i+6];
		else if(i==2)
		cout<<s[i+7];
		else if(i==1)
		cout<<s[i+8];
		else if(i==0)
		cout<<s[i+9];
		else 
		continue;
		}
		cout<<s[N];
	
	return 0;	
	}
