#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b,n=0,r;
	b=a.size();
	int c[b];
	for(int i=0;i<b;i++){
		if(a[i]-'0'>=0 && a[i]-'0'<10){
			c[n]=a[i]-'0';
			
			n++;}}
	sort(c,c+n);

	for(int i=n-1;i>=0;i--){
		cout<<c[i];}
	return 0;
}
