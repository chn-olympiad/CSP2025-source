#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10010];
int b,c,r,ans1,ans2;



int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n;j++){
			if(a[j]<a[j+1]){
				b=a[j+1];
				a[j+1]=a[j];
				a[j]=b;
			} 	
		}
	}
	for(int i=1;i<=m*n;i++){
		if(r==a[i]){
			c=i;
			break;
		}
	}
	if(c%n==0)ans1=c/n;
	else if(c%n!=0)ans1=(c/n)+1;
	if(ans1%2!=0){
		if(c%n==0)ans2=n;
		else ans2=c%n;
	}
	else if(ans1%2==0){
		if(c%n==0)ans2=1;
		else{
		
			if((c%n)-n>=0){
				ans2=(c%n)-n+1;
			}
			else if((c%n)-n<0){
				ans2=n-(c%n)+1;
			}
		}
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
