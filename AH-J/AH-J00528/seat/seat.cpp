#include<bits/stdc++.h>
using namespace std;
long long n,i,m,s,l,a[100009],b[100009],j;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=i;
	}
	for(i=1;i<=n*m-1;i++){
		for(j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				swap(b[i],b[j]);
			}
		}
	}
	for(i=1;i<=n*m;i++){
		if(b[i]==1){
			s=i;
			break;
		}
	}
	if(s%n==0){
		l=s/n;
		if(l%2==0)cout<<"1 "<<l;
			else cout<<n<<" "<<l;
	}else{
	l=s/n+1;
	cout<<l<<" "<<s-(l-1)*n;
}
	return 0;
}
