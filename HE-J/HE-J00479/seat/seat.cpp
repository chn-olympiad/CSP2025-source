#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int R,ansi,ansj;
int mp[15][15];
int lezi,zimo;
void oo(int &ll,int &rr){
	int c=ll;
	ll=rr;
	rr=c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	R=a[1];
	for(int i=1;i<=s;i++){
		int maxx=a[i];
		int ans=i;
		for(int j=i+1;j<=s;j++){
			if(a[j]>maxx){
				maxx=a[j];
				ans=j;
			}
		}
		oo(a[i],a[ans]);
	}
	
	
	if(m%2==0){
		lezi=0;
		for(int j=1;j<=m/2;j++){
			++zimo;
			for(int i=1;i<=n;i++){
				mp[i][zimo]=a[++lezi];
			}
			++zimo;
			for(int i=n;i>=1;i--){
				mp[i][zimo]=a[++lezi];
			}
		}
	}
	else if(m%2==1){
		lezi=0;
		for(int j=1;j<=m/2+1;j++){
			++zimo;
			for(int i=1;i<=n;i++){
				mp[i][zimo]=a[++lezi];
			}
			++zimo;
			for(int i=n;i>=1;i--){
				mp[i][zimo]=a[++lezi];
			}
		}
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==R){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
