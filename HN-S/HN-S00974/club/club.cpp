#include<bits/stdc++.h>
using namespace std;
int n,t,xam=0,a[10081],b[10081],c[10081];
void A(int m,int n1,int p1,int p2,int p3){
	if(n1==n+1){
		xam=max(xam,m);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&p1+1<=n/2){
			A(m+a[n1],n1+1,p1+1,p2,p3);
		}
		if(i==1&&p2+1<=n/2){
			A(m+b[n1],n1+1,p1,p2+1,p3);
		}
		if(i==1&&p3+1<=n/2){
			A(m+c[n1],n1+1,p1,p2+1,p3);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int ans[1001];
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int f=1;f<=n;f++){
			cin>>a[f]>>b[f]>>c[f];
		}
		A(0,1,0,0,0);
		ans[i]=xam;
		xam=0;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i];
	}
	return 0;
}
