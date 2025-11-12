#include<bits/stdc++.h>
using namespace std;
string a,b;
long long n[1000000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b+=a[i];
		}
	}
	for(long long i=0;i<b.size();i++){
		n[i]=b[i]-'0';
	}
	long long m=b.size();
	sort(n+0,n+m+0,cmp);
	for(long long i=0;i<b.size();i++){
		cout<<n[i];
	}
	return 0;
}
