#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[100];
	int e,t;
	t=n*m;
	cin>>e;
	for(int i=1;i<=t-1;i++){
		cin>>a[i];
	}
	
	int cnt,g,b[120];
	for(int i=1;i<=t+1;i++){
		g=110;
		for(int j=1;j<=t;j++){
			if(a[j]<g){
				g=a[j];
				cnt=j;
			}
		}
		b[i]=g;
		a[cnt]=110;

	}
	for(int i=1;i<=t-1;i++){
		cout<<b[i];
	}
	int ans;
	for(int i=1;i<=t;i++){
		if(e<b[i]){
			ans=i;
			break;
		}
	}

	ans=t-ans+1;
	
	
	int d=ans+n-1;
	int c,r;
	c=d/n;
	r=n-ans%n+1;
	cout<<c<<' '<<r;
	return 0;
}





