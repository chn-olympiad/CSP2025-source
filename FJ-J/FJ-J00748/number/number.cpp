#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],ji=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int b=s[i];
		if(b>=48&&b<=57){
			a[++ji]=b;
		}
	}
	sort(a+1,a+1+ji);
	for(int i=ji;i>=1;i--){
		cout<<a[i]-48; 
	}
	return 0;
}
