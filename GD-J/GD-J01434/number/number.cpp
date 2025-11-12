#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long n,a[1000001];
	string s;
	cin>>s;
	for(int i=0;i<=9;i++){
		a[i]=0;
	}
	
	for(long long i=0;sizeof(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(s[i]-'1')+1]++;
		}
	}
	for(long long i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++)cout<<i;
		}
	}
	return 0;
}
