#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin >> n >> m;
	int a1;
	cin >> a1;
	a[0]=a1;
	for(int i=1;i<n*m;i++){
		cin >> a[i];
	}
	sort(a,a+n*m);
	int sn,sm,s;
	for(int i=0;i<n*m;i++){
		if(a[i]==a1){
			s=n*m-i;
			break;
		}
	}
	sm=s/n+1;
	if(sm%2==1){
		sn=s%n;
		if(sn==0)sn=n;
	}
	else{
		sn=n-(s%n)+1;
		if(sn==n+1)sn=1;
	}
	cout << sm << ' ' << sn;
}
