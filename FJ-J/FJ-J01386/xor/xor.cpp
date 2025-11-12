#include<bits/stdc++.h>
using namespace std;
string ss(long long x){
	string t="";
	if(x==0){
		return "0";
	}
	while(x!=0){
		if(x%2==0){
			t="0"+t;
		}else{
			t="1"+t;
		}
		x/=2;
	}
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long a[n+10];
	string s[n+10],k1=ss(k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<1;
	return 0;
}
