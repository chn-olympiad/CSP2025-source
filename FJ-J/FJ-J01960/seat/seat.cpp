#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[200],c=0,r=0,i,j,t;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)	cin>>a[i];
	int d=a[1];
	
	for(i=1;i<=n*m-1;i++){
		for(j=i+1;j<=n*m;j++){
			if(a[i]<a[j])	swap(a[i],a[j]);
		}
	}
	for(i=1;i<=m*n;i++)	if(a[i]==d)		t=i;
	
	int u=t/n;
	if(t%n==0){c=u;
		if(u%2==0)	r=1;
		else	r=n;
	}
	else{c=u+1;
		if(c%2==0){
			for(i=n;i>=1;i--)	if(a[u*n+n-i+1]==d)	r=i;
		}
		else{
			for(i=1;i<=n;i++)	if(a[u*n+i]==d)		r=i;
		}
	}
	cout<<c<<" "<<r<<endl;
	return  0;
}
