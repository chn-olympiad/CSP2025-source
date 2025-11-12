#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
int a[200];
int p=1;
int ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])p++;
	}
	ansy=ceil(p*1.0/n);
	ansx=p%n;
	if(ansx==0)ansx=n;
	if(ansy%2==0){
		ansx=n-ansx+1;
	}
	cout<<ansy<<' '<<ansx;
	return 0;
}

