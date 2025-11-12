#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100005],b[100005],c[100005];
int club(int m,int a1,int b1,int c1,long long k){
	long long x=0,y=0,z=0;
	if(m<n){
		if(a1+1<=n/2){
			x=club(m+1,a1+1,b1,c1,k+a[m]);
		}
		if(b1+1<=n/2){
			y=club(m+1,a1,b1+1,c1,k+b[m]);
		}
		if(c1+1<=n/2){
			z=club(m+1,a1,b1,c1+1,k+c[m]);
		}
		return max(max(x,y),z);
		x=0;y=0;z=0;
	}
	else if(m==n){
		if(a1+1<=n/2){
			x=k+a[m];
		}
		if(b1+1<=n/2){
			y=k+b[m];
		}
		if(c1+1<=n/2){
			z=k+c[m];
		}
		return max(max(x,y),z);
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int op;cin>>op;
	while(op--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<club(1,0,0,0,0)<<endl;
	}
	return 0;
}
