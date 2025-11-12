#include<bits/stdc++.h>
using namespace std;
string s;
long long x=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int a[s.size()];
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[i]=s[i]-'0';
			x++;
		}
	}
	sort(a+0,a+s.size());
	for(int i=s.size()-1;i>=0;i--){
		if(a[i]<=9&&a[i]>=0&&x>0){
			cout<<a[i];
			x--;
		}
	}
	return 0;
} 
//	freopen("number.out","w",stdout)
