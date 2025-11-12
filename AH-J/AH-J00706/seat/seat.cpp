#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n,m,a[1000],l,n3;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+n*m+1);
	n3=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[n3]==l){
				cout<<i<<" "<<j;
				return 0;
			}
			n3--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
