#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],x,zb;

bool cmp(int p,int q){
	return p>q;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=(n*m);i++){
		if(a[i]==x){
			zb=i;
			break;
		}
	}
	int l=ceil(1.0*zb/n);
	int h=zb-(zb-1)/n*n;
	cout<<l<<" ";
	if(l%2!=0)
		cout<<h;
	else
		cout<<n-h+1;
	return 0;
}
