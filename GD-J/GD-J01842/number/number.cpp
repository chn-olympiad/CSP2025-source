#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int n=0; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
