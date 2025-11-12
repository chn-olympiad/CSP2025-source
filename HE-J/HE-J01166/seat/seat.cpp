#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[200],b[200],c[200],p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	q=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m*n;i++){
		if(a[i]==q){
			p=n*m-i;
			break;
		}
	}
	int mp=1,mb=1,mbb=0;
	bool f=false;
	for(int i=1;i<=n*m;i++){
		c[i]=mb;
		mbb++;
		if(mbb==n){
			mbb=0;
			mb++;
		}
	}
	for(int i=1;i<=m*n/2+1;i++){
		for(int s=1;s<=m;s++){
			b[mp]=s;
			mp++;
		}
		for(int s1=m;s1>=1;s1--){
			b[mp]=s1;
			mp++;
		}
	}
	cout<<c[p+1]<<" ";
	cout<<b[p+1];
}

