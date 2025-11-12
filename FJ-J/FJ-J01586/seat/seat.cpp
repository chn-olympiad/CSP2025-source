#include<bits/stdc++.h>
using namespace std;
int n,m,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+10];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	w=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++)
			if(a[i]<a[j]){
				int q=a[i];
				a[i]=a[j];
				a[j]=q;
			}
	}
	for(int i=1;i<=n*m;i++){
		if(w==a[i]){
			w=i;
			break;
		}
	}
	cout<<(w+n-1)/n<<' ';
	if(((w+n-1)/n)%2==1) cout<<(w-1)%n+1;
	else cout<<n-(w-1)%n;
}
