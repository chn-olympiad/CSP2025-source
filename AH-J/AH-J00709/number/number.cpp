#include<bits/stdc++.h>
using namespace std;
long long num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long l=a.size()-1;
	for(int i=0;i<=l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[a[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
