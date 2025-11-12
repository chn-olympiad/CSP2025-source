#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000000];
int ans,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<(s.size());i++){
		if(s[i]>='0' and s[i]<='9'){
			n++;
			a[ans]=s[i]-'0';
			ans++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
}
