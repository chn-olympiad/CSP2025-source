#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000005]={};
	
	int b=s.length();

	for(int i=0;i<b;i++){
		a[i]=-1;
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=int(s[i]-'0');
		}
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--){
		if(a[i]>=0){
			cout<<a[i];
		}
	}
	
	return 0;
}
