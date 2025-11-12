#include<bits/stdc++.h>
using namespace std;
int n,m,n1,a[110],a1,maxa=-1,t[110],lkg,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	n1=n*m;
	for(int i=1;i<=n1;i++){
		cin>>a[i];
		if(a[i]>maxa)maxa=a[i];
		t[a[i]]=1;
	}
	a1=a[1];
	for(int i=maxa;i>=a1;i--){
		if(t[i]==1)lkg++;
	}
	if(lkg%n==0){
		x=lkg/n;
		if(x%2==1)y=n;
			 else y=1;
	}
	else {
		x=lkg/n+1;
		int kg=lkg%n;
		if(x%2==1)y=kg;
			 else y=n-kg+1;
	}
	cout<<x<<" "<<y;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
