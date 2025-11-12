#include<bits/stdc++.h>
using namespace std;
int a[1005],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	int sum=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
		sum=n*m-i+1;
	break;
	}
	}
	int l=sum/n,r=sum%n;
	if(r==0){
		if(l%2==0){
			cout<<l<<' '<<1;
		}
		else{
			cout<<l<<' '<<n;
		}
	}
	else if(r!=0){
		if((l+1)%2==0){
			cout<<l+1<<' '<<n-r+1;
		}
		else if((l+1)%2!=0){
			cout<<l+1<<' '<<r;
		}
	}
	return 0;
}
