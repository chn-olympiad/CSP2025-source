#include<bits/stdc++.h>
using namespace std;
long long b[1000500];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int n=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			n++;
			b[n]=a[i]-'0';
		}
	}
	sort(b+1,b+1+n);
	for(int i=n;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 
