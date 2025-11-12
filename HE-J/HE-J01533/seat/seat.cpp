#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],number=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) number++;
	}
	if(number<n) cout<<1;
	else if(number%n==0) cout<<number/n;
	else cout<<(number/n)+1;
	cout<<" ";
	if(number%n==0){
		if((number/n)%2==0) cout<<1;
		else cout<<n;
	}
	else if((number/n)%2==0) cout<<number%n;
	else cout<<n-(number%n)+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
