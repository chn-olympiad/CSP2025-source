#include <bits/stdc++.h>
using namespace std;
/*
3 3
94 95 96 97 98 99 100 93 92
*/
int n,m;
int a[15][15],v[110],k,zb,hzb,zzb;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
		cin>>v[i];
	k=v[1];
	sort(v+1,v+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(v[i]==k){
			zb=i;
		}
	}
	hzb=ceil(zb*1.0/n);
	cout<<hzb<<' ';
	zzb=zb%n;
	if(hzb%2==0){
		zzb=n-zzb+1;
	}else if(hzb%2==1&&zzb==0){
		zzb=n;
	}
	cout<<zzb;
	return 0;
}