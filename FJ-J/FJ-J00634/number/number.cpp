#include<bits/stdc++.h>
using namespace std;
string a;
long long n=0,b[1000000]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-0>=48 && a[i]-0<=57){
			if(a[i]-0==57){
				cout<<a[i]-48;
			}
			else{
				b[n]=a[i]-48;n++;
			} 
		}
	}sort(b,b+n);
	for(int i=n-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}

