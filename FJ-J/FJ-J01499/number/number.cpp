#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
string s;
long long n,a[N],p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char m:s){
		if(int(m)<=57 && int(m)>=48){
			a[p++]=m-48;
		}
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<p;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<p;i++){
		cout<<a[i];
	}
	return 0;
}
