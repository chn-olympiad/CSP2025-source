#include <bits/stdc++.h>
using namespace std;
string b;
long long a[1000005],js=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(long long i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[js++]=b[i]-'0';
		}
	}
	sort(a,a+js,cmp);
	for(long long i=0;i<js;i++){
		cout<<a[i];
	}
	return 0;
}
