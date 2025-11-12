#include<bits/stdc++.h>
using namespace std;
string n;
long long a[10],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			t=n[i]-'0';
			a[t]++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

