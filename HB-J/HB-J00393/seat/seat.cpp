#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],ms,mi,lie;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){ 
		cin>>a[i];
		if(i==1){
			ms=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){ 
		if(a[i]==ms){
			mi=i;
			break;
		}
	}
	lie=(mi/(2*n))*2+(mi%(2*n))/n+1;
	if((mi%(2*n))%n==0){
		if(lie%2==1){
			cout<<lie-1<<" "<<1;
		}
		else{
			cout<<lie-1<<" "<<n;
		}
	}
	else{
		if(lie%2==1){
			cout<<lie<<" "<<1+(mi%(2*n))%n-1;
		}
		else{
			cout<<lie<<" "<<n-(mi%(2*n))%n+1;
		}
	}

	return 0;
}
