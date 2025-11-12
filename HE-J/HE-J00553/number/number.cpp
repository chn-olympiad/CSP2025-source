#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		while(b[i]!=0){
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}


