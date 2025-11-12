#include<bits/stdc++.h>
using namespace std;
#define long long int
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[101];
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++){
	    cin>>a[i];	
	}
	int r=a[0],count=1;
	for(int i=1;i<=n*m-1;i++){
	    if(a[i]>r)	count++;
	}
	int ans1,ans2;
	if(count%n==0) ans1=count/n;
	else ans1=count/n+1;
	int x=count-(ans1-1)*n;
	if(ans1%2==0) ans2=n-x+1;
	else ans2=x;
	cout<<ans1<<" "<<ans2;	
	return 0;
}
