#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,a[101];
	int n,ans;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	for(int c=1;c<=n*m;c++){
		for(int d=1;d<n*m;d++){
			if(a[d]<a[d+1]){
				swap(a[d],a[d+1]);
			}
		}
	}
	for(int e=1;e<=n*m;e++){
		if(b==a[e]){
			ans=e;
		}
	}
	int f;
	if(ans<n){
		f=ans;
	}
	else{
		if(ans%n!=0){
			f=ans/n+1;	
		}
		else{
			f=ans/n;
		}
	}
	int seatn=0,seatm=0;
	if(int(f)%2!=0){
		seatm=int(f);
		if(ans%n==0){
			seatn=n;
		}
		else{
			seatn=ans%(n);
		}
		
	}
	else{
		seatm=int(f);
		if(ans%n==0){
			seatn=n-ans%n-1;
		}
		else{
			seatn=n-ans%n+1;
		}
		
	}
	cout<<seatm<<" "<<seatn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
