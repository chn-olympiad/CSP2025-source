#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
char a[N];
char b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<=s.length();i++){
		a[i]=s[i];
	}
	for(int i=0;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i];
		}
	}
	sort(b,b+n);
	for(int i=n;i>=0;i--){
		if(b[i]!=0){
			cout<<b[i];
		}
		
	}
	return 0;
}
