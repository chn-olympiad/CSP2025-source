#include<bits/stdc++.h>
using namespace std;	
int a[100001],j=1,len;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;s[i]!='/0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	for(int i=1;i<=j;i++){
		for(int k=1;k<=j;k++){
			if(a[k]>a[k]+1)swap(a[k],a[k+1]);
		}
	}
	for(int i=1;i<=j;i++){
		cout<<a[i];
	}
} 
