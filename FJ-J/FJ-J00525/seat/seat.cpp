#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int phs=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]>a[1]) phs++;
		}
	}
	int t=0;
	for(int i=1;i<=m;i++){
		t+=n;
		if(t>=phs){
			break;
		}
	}
	cout<<t/n<<" ";
	if(t==phs){
		if((t/n)%2==0) cout<<1;
		else cout<<n;	
		return 0;		
	}
	if((t/n)%2==0) cout<<n-(t-phs)+1;
	else cout<<phs-n*((t-n)/n);
	return 0;
}
