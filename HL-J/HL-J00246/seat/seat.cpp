#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,location,rows,lines;
	cin>>n>>m;
	int a[n*m+10],grades[n*m+10];
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		R=a[1];
	}
	for (int i=1;i<=m*n;i++){
		for (int j=1;j<=i;j++){
			if (a[i]>a[j]){
				int t=a[i];a[i]=a[j];a[j]=t;
			}
		}
	}
	for (int i=1;i<=m*n;i++){
		if (a[i]==R){
			location=i;
			break;
		}
	}
	if (location%n==0) lines=location/n;
	else lines=location/n+1;
	if (lines%2==0){
		rows=n-(location-(lines-1)*n)+1;
	}
	else{
		rows=location-(lines-1)*n;
	}
	cout<<lines<<" "<<rows;
	fclose(stdin);
	fclose(stdout);
	return 0;
}