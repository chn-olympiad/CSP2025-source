#include<bits/stdc++.h>
using namespace std;
string a;
long long b,c[1000001],d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]-0>=48&&a[i]-0<=57){
			c[d]=a[i]-48;
			d++;
		}
	}
	sort(c,c+d);
	for(long long i=d-1;i>=0;i--){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
