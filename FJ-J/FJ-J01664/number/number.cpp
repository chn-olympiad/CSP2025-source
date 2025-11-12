#include<bits/stdc++.h>
using namespace std;
long long ans=0;
char a[10000009]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long b[strlen(a)]={}; 
	for(long long i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans++;
			b[ans]=a[i]-'0';
		}
	}
	sort(b,b+ans+1);
	for(long long i=ans;i>=1;i--){
		cout<<b[i];
	}
}
