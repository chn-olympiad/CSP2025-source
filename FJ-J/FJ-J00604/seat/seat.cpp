#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int main()
{
	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1);
	int k;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			k=n*m-i+1;
			break;
		}
	}
	int c,r;
	if(k%n>0){
		r=k/n+1;
		if(r%2==1){
			c=k%n;
		}
		else if(r%2==0){
			c=n-k%n+1;
		}
	}
	else if(k%n==0){
		r=k/n;
		if(r%2==1){
			c=n;
		}
		else if(r%2==0){
			c=1;
		}
	}
	cout<<r<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
