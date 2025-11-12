#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,x,l,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==x){
			x=n*m-i+1;
			break;
		}
	k=x/n;
	l=x%n;
	if(l==0){
		cout<<k<<' ';
		if(k%2==0) cout<<'1';
		else cout<<m;
		return 0; 
	}
	if(k%2==1) cout<<k+1<<' '<<m-l+1;
	else cout<<k+1<<' '<<l;
	return 0;
}
