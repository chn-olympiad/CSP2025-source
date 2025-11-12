#include<bits/stdc++.h>
using namespace std;
int m,n,a[101],x,y,ans,g;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	ans=m*n;
	for(int i=1;i<=ans;i++){
		scanf("%d",&a[i]);
	}
	g=a[1];
	sort(a+1,a+ans+1);
	for(int i=ans;i>=1;i--){
		if(a[i]==g){
			ans=ans-i+1;
		}
	}
	y=(ans-1)/n+1;
	if(y%2==0){
	  x=n-ans%n+1;	
	}else{
	  x=ans-y*n+n;	
	}
	cout<<y<<' '<<x;
	return 0;
}
