#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[108],R,num,ls;
	cin>>n>>m;
	int k=n*m;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	R=a[0];
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++){
		if(a[i]==R){
			num=i+1;
			break;
		}
	}
	int zs=num/(n*2+1)+1;
	int ks=num%(2*n+1);
	if(ks>n) ls=zs*2;
	else ls=zs*2-1;
	cout<<ls<<" ";
	if(ks>n) cout<<2*n+1-ks;
	else if(ks==0) cout<<1;
	else cout<<ks;
	return 0;
}
