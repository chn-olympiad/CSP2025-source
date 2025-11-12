#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans=1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	int c=a[1];
	for(int i=1;i<=n*m;i++) {
		for(int j=i+1;j<=n*m;j++) {
			if(a[i]<a[j]) {
				int g=a[i];
				a[i]=a[j];
				a[j]=g;
			}
		}
	}
	for(int i=1;i<=n*m;i++) {
		if(a[i]==c) {
			break;
		} else {
			ans++;
		}
	}
	int f=ans%m;
	int q=ans/m;
	if(f) {
		q++;
	}
	if(q%2==0) {
		if(f==0) {
		    cout<<q<<" "<<1;
	    }
	    if(f==1) {
		    cout<<q<<" "<<m;
	    }
	    if(f==2) {
	    	cout<<q<<" "<<m-1;
		} 
		if(f==3) {
	    	cout<<q<<" "<<m-2;
		} 
		if(f==4) {
	    	cout<<q<<" "<<m-3;
		} 
		if(f==5) {
	    	cout<<q<<" "<<m-4;
		} 
		if(f==6) {
	    	cout<<q<<" "<<m-5;
		} 
		if(f==7) {
	    	cout<<q<<" "<<m-6;
		} 
		if(f==8) {
	    	cout<<q<<" "<<m-7;
		} 
		if(f==9) {
	    	cout<<q<<" "<<m-8;
		} 
	} else {
		cout<<q<<" "<<ans%m;
	}
	return 0;
}