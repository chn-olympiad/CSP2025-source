#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	char b[1000005];
	cin>>a;
	int n=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[n]=a[i];
			n++;
		}
	}
	sort(b,b+n);
	for(int i=n-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
