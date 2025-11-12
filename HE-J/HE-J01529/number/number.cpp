#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],b,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s.size();
	for(long long i=0;i<b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long u=1;u<=a[i];u++){
			cout<<i;
		}
	}
	return 0;
}
