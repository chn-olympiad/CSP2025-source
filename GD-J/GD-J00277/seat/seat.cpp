#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],rk=1,hang=0,lie=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])rk++;
	}
	lie=(rk+n-1)/n;
	if(lie%2){
		if(rk%n==0)hang=n;
		else hang=rk%n;
	}
	else {
		if(rk%n==0)hang=1;
		else hang=n-rk%n+1;
	}
	cout<<lie<<" "<<hang;
	fclose(stdout);
	fclose(stdin);
	return 0;
} 
