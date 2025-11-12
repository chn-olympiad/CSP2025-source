#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(number.in,"r",stdin);
	freopen(number.out,"w",stdout);
	string a;
	getline(cin,a);
	int c=0,l=a.size();
	int b[c];
	for(int i=0;i<l;i++){
		if(a[i]>='0' && a[i]<='9'){
			c++;
			b[c]=a[i]%48;
		}
	}
	sort(b,b+l);
	for(int i=c;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
