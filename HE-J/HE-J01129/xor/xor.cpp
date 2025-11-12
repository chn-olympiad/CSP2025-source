#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,j,n,k,d=0,c;
	int a[10000];
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i];
		d=d+a[i];
	}
	c=(d+k)/n;
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
