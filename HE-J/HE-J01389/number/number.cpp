#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.length();
	char q[1000001]={};
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9'){
			q[i]=a[i];
		}
	}
	sort(q,q+n);
	for(int i=n-1;i>=0;i--){
		cout<<q[i];
	}
	return 0;
}
