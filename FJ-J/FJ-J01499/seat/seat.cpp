#include<bits/stdc++.h>
using namespace std;

long long n,m,c,b,k,p,a[100005],l[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		l[i]=a[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==l[0]){
			p=i+1;
		}
	}
	if(p%n==0){
		c=p/n;
		if(p/n%2==0)k=1;
		else k=n;
	}else{
		c=p/n+1;
		if(p/n%2==0)k=n-p%n-1;
		else k=p%n+1;
	}
	cout<<c<<" "<<k;
	return 0;
}
