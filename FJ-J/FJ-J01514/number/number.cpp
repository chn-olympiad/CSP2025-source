#include <bits/stdc++.h> std;
using namespace std;
string a;
int b[1000000];
int bs;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[bs]=int(a[i])-48;
			bs++;
		}
	}
	sort(b,b+bs);
	
	for(int i=bs;i>0;i--){
		cout<<b[i-1];
	}
	return 0;
}
