#include<bits/stdc++.h>
using namespace std;
int a[109];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,j;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>a[1];
			k=a[1];
		}
		else cin>>a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			j=i;
		}
	}
	int l;
	if(j%n==0) l=j/n;
	else l=j/n+1;
	cout<<l<<" ";
	if(j%n==0){
		if(l%2==0) cout<<1;
		else cout<<n;
		return 0;
	}
	if(l%2==0){
		cout<<n-(j%n)+1;
	}
	else cout<<j%n;
	return 0;
}
