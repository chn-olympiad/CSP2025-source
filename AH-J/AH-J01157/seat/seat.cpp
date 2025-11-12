#include<bits/stdc++.h>
using namespace std;
int n,m,x,l,a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];	
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			 l=i;
			 break;
		}
	}
	l=n*m-l+1;
	int h=l%n;
	if(l%n==0) h=n;
	if(h==0) h+=1;
	if(l<=n) l=1;
	else l=(l/n)+1;
	if(l%2==1) cout<<l<<" "<<h;
	else cout<<l<<" "<<n-h+1;
	return 0;
}
