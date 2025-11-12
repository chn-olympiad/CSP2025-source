#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,l,qu;
int a[114];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])
			ans++;
	}
	if(ans%n==0){
		l=ans/n;
		if(l%2==0)
		{
			cout<<l<<" "<<1;
		}
		else{
			cout<<l<<" "<<n;
		}
	} 
	else if(ans%n!=0){
		l=ans/n+1;
		qu=ans%n;
		if(l%2==0)
		{
			if(qu==1)
				cout<<l<<" "<<n;
			else
				cout<<l<<" "<<n/qu+1;
		}
		else{
			cout<<l<<" "<<ans%n;
		}
	}
	return 0;
}
