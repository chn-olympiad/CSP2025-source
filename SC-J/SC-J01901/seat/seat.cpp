#include<bits/stdc++.h>
using namespace std;
int a[105];
int c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=m*n;
	for(int i=1;i<=f;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+f+1);
	for(int i=1;i<=f;i++){
		if (k==a[i]) {
		    c=m*n-i+1;	
		}
	}
	int j=(c-1)/n+1;
	if(j%2!=0&&c%n!=0) cout<<j<<" "<<c%4;
	else if(j%2!=0&&c%n==0) cout<<j<<" "<<n;
	else if(j%2==0&&c%n!=0) cout<<j<<" "<<n-c%n+1;
	else cout<<j<<" "<<1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}