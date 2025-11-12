#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000001],b;
bool mysort(int x,int y){
	if(x>y)	return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		char x=s[i];
		if(x>='0'&&x<='9'){
			a[++b]=x-'0';
		}
	}
	sort(a+1,a+b+1,mysort);
	for(int i=1;i<=b;i++){
		cout<<a[i];
	}
	return 0;
}
