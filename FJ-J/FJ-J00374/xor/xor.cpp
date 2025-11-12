#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, sum=0;
	cin >> n >> k;
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
		if(a[i]==1)sum++;
	}
	if(k==1) {
		cout<<sum;
	}
	if(k==0) {
		sum=0;
		for(int i=0; i<n; i++) {
			if(a[i]==1 && a[i+1]==1) {
				sum++;
				i++;
			}
			if(a[i]==0)sum++;
		}
		cout<<sum;
	} 
	else {
		sum=0;
		int d=a[0];
		for(int i=1; i<n; i++) {	
			if(d==k) {
				sum++;
				d=a[i];
				i++;
			}
			else d=d^a[i];
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}