#include<bits/stdc++.h>
#include<string>
using namespace std;

short int b[1000005];


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.length();
	for(int i=0;i<n;i++){
		b[i]=a[i]-'0';
	}
	sort(b,b+n);
	for(int i=n-1;i>=0;i--){
		if(b[i]>9){
			continue;
		}else{
			cout<<b[i];
		}
	}
	return 0;
}

