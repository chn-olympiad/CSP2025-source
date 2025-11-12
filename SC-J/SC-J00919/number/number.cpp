#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000003];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	int m=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m++;
			a[m]=s[i]-'0';
		}
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}