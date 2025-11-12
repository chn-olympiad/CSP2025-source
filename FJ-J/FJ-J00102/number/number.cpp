#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int l=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}