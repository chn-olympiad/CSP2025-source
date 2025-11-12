#include<bits/stdc++.h>
using namespace std;
int x,y,m,n,a[10009],cnt[109],s=0,t;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	t=a[1];
	for(int i=100;i>=a[1];i--){
		s+=cnt[i];
	}
	if(s%n==0)x=s/n;
	else x=s/n+1;
	if(x%2!=0){
		if(s%n!=0)y=s%n;
		else y=n;
	}	
	else{
		 if(s%n!=0)y=n-s%n+1;
		 else y=1;
	 }
	cout<<x<<" "<<y;
	return 0;
}
