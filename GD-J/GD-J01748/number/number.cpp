#include<bits/stdc++.h>
using namespace std;
string a;
long long s[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[int(a[i]-'0')]+=1;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<s[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
