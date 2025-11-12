#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int c=0;
	cin>>a;
	for(int i=0;i<=a.length()-1;i++){
		if(a[i]>='0' && a[i]<='9'){
			c++;
			b[c]=a[i]-'0';
		} 
	} 
	sort(b+1,b+c+1);
	for(int i=c;i>=1;i--) cout<<b[i];
	
	return 0;
} 