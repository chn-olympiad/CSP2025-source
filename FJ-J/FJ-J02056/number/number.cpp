#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			n++;
			a[n]=s[i]-48;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
