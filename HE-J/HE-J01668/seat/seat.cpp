#include<bits/stdc++.h>
using namespace std;
long long n,m,R,ls=1,hs=1,hh,ll,l=1;
long long a[12][12],c[12][12],b[105];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	R=b[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(b[i]<b[j]){
				int t=b[j];
				b[j]=b[i];
				b[i]=t;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=b[l];
			l++;
		}
	}
	int x=1,y=1;
	for(int i=1;i<=n;i++){
		ls=1;x=1;
		if(hs%2!=0){
			for(int j=1;j<=m;j++){
				if(ls%2!=0) c[i][j]=a[x++][y];
				if(ls%2==0) c[i][j]=a[x++][y+n-1];
				ls++;
			}
		}else{
			for(int j=1;j<=m;j++){
				if(ls%2!=0) c[i][j]=a[x++][y-n+1];
				if(ls%2==0) c[i][j]=a[x++][y];
				ls++;
			}
		}
		hs++;y++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<c[i][j]<<" ";
			if(c[i][j]==R){
				hh=i;ll=j;
			}
		}
		cout<<endl;
	}
	cout<<hh<<" "<<ll;
	return 0;
}
