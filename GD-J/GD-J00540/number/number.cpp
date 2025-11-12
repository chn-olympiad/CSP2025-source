#include<bits/stdc++.h>
using namespace std;
string s;
vector <int> v;
int p;
	freopen("number.in"'r'stdin);
	freopen("number.out"'m'stdout);
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			p=s[i]-'0';
			v.push_back(p); 
		}
	}
	int n=v.size();
	int a[n];
	for(int i=0;i<n;i++){
	a[i]=v[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
