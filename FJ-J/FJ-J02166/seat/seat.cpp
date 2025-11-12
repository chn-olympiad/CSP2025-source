#include<bits\stdc++.h>
using namespace std;
long long n,m,v[200],a[300],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int tmp;
		cin>>tmp;
		if(i==1) ans=tmp;
		v[tmp]=1;
	}
	int s=1;
	for(int i=100;i>=1;i--){
		if(v[i]==1){
			a[s]=i;
			s++;
		}
	}
	s=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[s]==ans){
				cout<<i<<' ';
				if(i%2==1) cout<<j;
				else cout<<m-j+1;
				return 0;
			} 
			s++;
		}
	}
	return 0;
}
