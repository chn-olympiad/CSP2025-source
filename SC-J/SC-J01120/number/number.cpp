#include <bits/stdc++.h>
using namespace std;
string a;
long long  b[214748364],s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[s]=a[i]-'0';
			s++;
		}
	}
	sort(b,b+s);
	for (long long i=s-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}