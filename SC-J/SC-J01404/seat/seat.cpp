#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a[MAXN],n,m,x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a[0]){
			x=i;
			break;
		}
	}
	int n0=x%n,m0=(x+n-1)/n;
	cout<<m0<<' ';
	if(m0%2==1){
		if(n0==0) cout<<n;
		else cout<<n0;
	} 
	else{
		if(n0==0) cout<<1;
		else cout<<n-n0+1;
	}
	return 0;
} 