#include <bits/stdc++.h>
using namespace std;
int n,m,k,l,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	k=n*m;
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<n*m;i++)
		if(a[0]>a[i]){
			k=i;
			break;
		}
	l=k/n+((k%n!=0)?1:0);
	cout<<l<<" ";
	if(l%2==0){
		if(k%n==0)
			cout<<1;
		else cout<<n-k%n+1;
	}
	if(l%2==1){
		if(k%n==0)
			cout<<n;
		else cout<<k%n;
	}
	return 0;
}
