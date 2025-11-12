#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.cpp","r",stdin);
	freopen("seat.cpp","w",stdout);
	int l,r,n,k,maxx=0;
	int a[11000];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		int tot=0;
		if(a[i]!=0&&k==0)tot++;
		if(tot==n)cout<<0;
	}
	for(int i=1;i<=n;i++){
		int tot;
		if(a[i]==a[i+1])
	} 
	cout<<maxx;
	return 0;
}
