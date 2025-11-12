#include <bits/stdc++.h>
using namespace std;	
long long  n,m,ans,bl;	
long long q,w;
long long a[100][100],cj[100005];
bool f=0;

int main(){
	freopen(" seat.in","r",stdin);
	freopen(" seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	ans=cj[1];
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m;i++){
		if(cj[i]<cj[i+1]){
			q=cj[i];
			w=cj[i+1];
			cj[i+1]=q;
			cj[i]=w;

		}
	}
	}
	

	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
			bl++;	
			a[i][j]=cj[bl];
		}
		
		}else{
			for(int j=n;j>=1;j--){
				bl++;
				a[i][j]=cj[bl];}
		}
}for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f==0){
			if(a[i][j]==ans){
			cout<<i<<" "<<j<<endl;
			f=1;
		}
			}
		
		}
	}
}			

