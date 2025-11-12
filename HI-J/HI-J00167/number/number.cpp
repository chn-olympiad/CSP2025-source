#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000100]; 
	cin>>s;
	for(int i=1;i<=1000000;i++){
		if (s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9)
		a[i]=s[i];
	}
	for(int i=0;i<=1000100;i++){
		for(int j=1;j<=1000100;j++){
			if (a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=1000100;i++)cout<<a[i];
	return 0;
}
