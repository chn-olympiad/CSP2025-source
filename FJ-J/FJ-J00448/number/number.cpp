#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000001];
int main(){
	freeopen("number.in","r",stdin);
	freeopen("number.out","w",stdout);
	cin>>a;
	int c=0;
	for(int i=0;i<=a.size();i++){
		if('0'<=(a[i])&&a[i]<='9'){
			c++;
			b[c]=int(a[i]-'0');
		}
	}
	sort(b+1,b+c+1);
	for(int i=c;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 
