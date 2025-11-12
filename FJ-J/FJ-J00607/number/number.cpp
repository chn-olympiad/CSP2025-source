#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string str;
long long a[10];
int main( ){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(long long i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

