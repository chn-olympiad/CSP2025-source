#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n,m,x[250000+4000];
	string a;
	cin>>a;
	n=a.length();
	m=0;
	for(int i=0;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
		    m++;
			x[m]=a[i]-48;		
		}
	}
	sort(x+1,x+m+1);
	for(int i=m;i>=1;i--){
		cout<<x[i];
	}
	return 0;
}

