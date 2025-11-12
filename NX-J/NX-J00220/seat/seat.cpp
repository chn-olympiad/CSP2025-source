#include <bits/stdc++.h>
using namespace std;
int a[11][11],b[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++}{
		cin>>b[i];
	}
	int grade=b[1];
	for(int i=1;i<=n*m;i++}{
		for(int j=i+1;j<=m*n;i++}{
			if(a[j]>a[i])swap(a[j],a[i]);
		}
	}
	for(int i=1;i<=m*n;i++){
		if(b[i]=grade){
			int s=i/n;
			if(i%n!=0)l=s+1;
			else l=i/n;
			h=i-s*n;
		}
	}
	cout<<l<<' '<<h;
	return 0;
}
