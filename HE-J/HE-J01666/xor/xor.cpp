#include<bits/stdc++.h>
using namespace std;
int a[10010];
int maxn;
int qh(int x,int y) {
	bool a1[30],a2[30];
	int sumn=0;
	int n1=0,n2=0;
	while (x) {
		a1[n1+1]=x%2;
		n1++;
		x/=2;
	}
	while (y) {
		a1[n2+1]=y%2;
		n2++;
		y/=2;
	}
	int n3=max(n1,n2);
	for(int i=1;i<=n3-n1;i--) {
		a1[i+n1]=0;
	}
	for(int i=1;i<=n3-n2;i--) {
		a2[i+n2]=0;
	}
	int n=n1;
	for(int i=1;i<=n/2;i++) {
		swap(a1[i],a1[n1]);
		n1--;
	}
	n=n2;
	for(int i=1;i<=n/2;i++) {
		swap(a2[i],a1[n2]);
		n2--;
	}
	for(int i=1;i<=n3;i++) {
		if(a1[i]==a2[i]) {
			a1[i]=0;
		}
		if(a1[i]!=a2[i]) {
			a1[i]=1;
		}
	}
	for(int i=1;i<=n3;i++) {
		sumn+=a1[i]*pow(2,i-1);
	}
	return sumn;
}
int main() {
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==x) maxn=1;
	}
	for(int i=2;i<=n;i++) {
		int sum=0;
		for(int j=1;j<=n-i+1;j++){
			for(int c=j;c<=j+i-1;c++) {
				sum+=qh(sum,c);
			}
			if(sum==x){
				maxn=max(maxn,i);
				break; 
			}
		}
	}
	cout<<maxn;
}
