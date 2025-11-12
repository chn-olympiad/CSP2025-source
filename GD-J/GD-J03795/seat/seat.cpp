#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r,s,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*n+j];
			if((i-1)*n+j==1)
				s=a[(i-1)*n+j];
			else if(a[(i-1)*n+j]>s){
				ans++;
			}
		}
	}
//	cout<<s<<" "<<ans<<' ';
	c=(ans+n-1)/n;
	if(c%2==1){
		r=(ans-1)%n+1;
	}else{
		r=n-(ans-1)%n;
	}
	cout<<c<<' '<<r;
	return 0;
}
