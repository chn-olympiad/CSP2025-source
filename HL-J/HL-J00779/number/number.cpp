#include<bits/stdc++.h>
using namespace std;
int b[1001000]={},k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	
	
	for(int i=0;i<a.length();i++){
		if('0'<=a[i] && a[i]<='9'){
			b[k++]=a[i]-'0';
		}
	}
	sort(b,b+k);
	for(int i=k-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
