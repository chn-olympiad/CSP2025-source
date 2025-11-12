#include<bits/stdc++.h>
using namespace std;
string a;
int n,x[10000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	int j=1;
	for(int i=0;i<n;i++) {
		if(a[i]>='0'&&a[i]<='9') {
			x[j]=a[i]-'0';
			j++;
		}
	}
	sort(x+1,x+1+j);
	for(int i=j;i>1;i--) {
		cout<<x[i];
	}
	return 0;
} 
