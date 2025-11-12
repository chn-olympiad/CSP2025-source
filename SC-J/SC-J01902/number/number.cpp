#include<bits/stdc++.h>
using namespace std;
int n[1000009],s,q;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	q=a.length();
	for(int i=0;i<=q;i++){
		if(a[i]>='0'&&a[i]<='9'){
			s++;
			n[s]=a[i]-'0';
		}
	}
	sort(n+1,n+1+s);
	for(int i=s;i>0;i--){
		cout<<n[i];
	}
	return 0;
}