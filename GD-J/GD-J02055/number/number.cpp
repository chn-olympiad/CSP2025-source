#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000000];
long long c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		 if(a[i]<=57&&a[i]>=48){
		 	b[c]=a[i];
		 	c++;
		 }
	}
	sort(b,b+c);
	for(long long i=c;i>=0;i--){
		cout<<b[i];
	}
	return 0;
} 
