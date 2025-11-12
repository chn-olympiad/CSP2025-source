#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){a[n]=s[i]-'0';n++;}
	}
	for(int i=0;i<n;i++){
		int mx=-10;
		for(int j=0;j<n;j++){
			if(a[j]>a[mx])mx=j;
			
		}
		cout<<a[mx];
		a[mx]=-20;
	}
}
//JL-J00031
