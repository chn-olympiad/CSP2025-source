#include<bits/stdc++.h>
using namespace std;
int n,m,a[166];
int ansh,ansl;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],ad;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ad=i;
			break;
		}
	}
	ad=n*m-ad+1;
	ansl=ad/n;
	if(ad%n){
		ansl++;
	}
	ansh=(ansl%2)?((ad%n)?(ad%n):n):(((ad/n+1)*n-ad)==n?1:((ad/n+1)*n-ad+1));
	cout<<ansl<<' '<<ansh;
	return 0;
}
