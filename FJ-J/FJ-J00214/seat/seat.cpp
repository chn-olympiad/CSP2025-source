#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[1005],b[15][15],c,r,sum=0,aa,cc,rr;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	aa=a[0];
	sort(a,1+a+(n*m));
	for(int i=0;i<n*m;i++){
		if(a[n*m-i]==aa){
			if(i<n){
				c=1;
				r=n*m-i-1;
			}
			else if(i>=n){
				rr=n*m-i+1;
				if(rr/n%2==1){
					r=n*m-i;
				}else{
					r=n*m-rr-1;
				}
				c=n*m-i;
			}
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
