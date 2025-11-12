#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n,s="";
	cin>>n;
	char a[n.size()],c;
	long long j=0,b=n.size();
	for(long long i=0;i< b;i++){
		if(n[i]>='0' && n[i]<='9'){
			a[j]=n[i];
			j++;
			}
	}
	for(long long i=0;i<j;i++){
		for(long long i=0;i<j-1;i++){
		if(a[i]<a[i+1]){
			c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
			}
	}}
	for(long long i=0;i<j;i++){
		s+=a[i];
	}
	cout<<s;
	return 0;
}
