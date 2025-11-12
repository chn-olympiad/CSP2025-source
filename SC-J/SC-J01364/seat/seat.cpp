#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,h;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int b=a[1],w;
	for(int i=1;i<=n*m;i++)for(int j=i;j<=n*m;j++)if(a[i]<a[j+1])swap(a[i],a[j+1]);
	for(int i=1;i<=n*m;i++)if(a[i]==b)w=i;
	if(w%n==0)l=w/n;
	else l=w/n+1;
	if(l%2!=0){
		if(w%n!=0)h=w%n;
		else h=n;
	}
	else{
		if(w%n>0)h=n-w%n+1;
		else h=1;
	}
	cout<<l<<" "<<h;
	return 0;
}