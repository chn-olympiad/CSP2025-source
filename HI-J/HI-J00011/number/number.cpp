#include<bits/stdc++.h>
using namespace std; 
string s;
char a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if((int)s[i]>=48&&(int)s[i]<=57){
		a[i]=s[i];
		}
		
	}
	for(int i=0;i<=s.size();i++){
		for(int j=0;j<=s.size();j++){
			if((int)a[i]>(int)a[j]){
				int h=a[j];
				a[j]=a[i];
				a[i]=h;
			}
		}
	}
	for(int i=0;i<=s.size();i++){
		cout<<(char)a[i];
	}
	return 0;
}
