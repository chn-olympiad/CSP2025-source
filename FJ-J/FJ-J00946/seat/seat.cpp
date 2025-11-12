#include<bits/stdc++.h>
using namespace std;

int n,m,a[105];
int c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int k=a[1];
	sort(a+1,a+n*m+1);
	int x=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k) x=i;
	}
	x=n*m-x+1;
	c=x/n;
	if(x%n!=0) c++;
	if(c%2==1){
		r=x%n;
	}else{
		r=n+1-x%n;
	}
	if(r==0) r=n;
	cout<<c<<" "<<r;
	
	return 0;
} 
