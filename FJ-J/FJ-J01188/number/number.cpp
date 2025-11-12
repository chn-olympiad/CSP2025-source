#include<bits/stdc++.h>
using namespace std;
int n,cnt,num[15];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9') ++num[a[i]-'0'];
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++) putchar(i+'0');
	}
	return 0;
} 
