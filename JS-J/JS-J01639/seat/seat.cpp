#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],k,p,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		//cout<<a[i]<<' ';
		if(a[i]==k){
			p=n*m-i+1;
		}
	}
	//cout<<p<<endl;
	l=ceil(p*1.0/n);
	r=p-(l-1)*n;
	printf("%d %d",l,l%2==1 ? r : n-r+1);
	return 0;
}
