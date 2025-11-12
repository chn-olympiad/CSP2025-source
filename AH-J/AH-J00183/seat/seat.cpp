#include<bits/stdc++.h>
using namespace std;

int a[20],b[20];
int main(){
    freopen("seat.in","r",stdin);
	int n,m,q,p;
	cin>>n>>m;
	cin>>a[1];
	q=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==q) p=i;
	}
	p=n*m-p+1;
	if((p%m==0)&&((p/m)%2==0)) cout<<p/m<<" "<<1;
	else if(p%m==0) cout<<p/m<<" "<<m;
	else if((p/m+1)%2==0) cout<<p/m+1<<" "<<n-p%m+1;
	else cout<<p/m+1<<" "<<p%m;
   freopen("seat.out","w",stdout);
    return 0;
}
