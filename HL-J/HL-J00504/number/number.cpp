#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0,n;
	string s;
	cin>>s;
	for(int i=0;i<=1;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[i]=s[i]-'0';
		}
		else{
			a[i]=a[i+1];
		}
	}
	for(int i=0;i<=1;i++){
		if(a[i]<a[i+1]){
			k=a[i];
			a[i]=a[i+1];
			a[i+1]=k;	
		}
	}
	cout<<a[0];
	return 0;
}