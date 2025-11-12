#include<bits/stdc++.h>
using namespace std;
int a;
long long t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	for(long long i=0;i<n;i++){
		a=s[i]-'0';
		if(a>=0 && a<=9){
			t[a]++;
		}
	}
	for(long long  i=9;i>=0;i--){
		for(long long  j=1;j<=t[i];j++){
			cout<<i;
		}
	}		
	return 0;
}
