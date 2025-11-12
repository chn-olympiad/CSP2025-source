#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,j,n,c=0,d;
	int a[10000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		c=c+a[i];
	}
	j=(c-n)/2;
	cout<<c-j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
