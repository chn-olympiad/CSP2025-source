#include<bits/stdc++.h> 
using namespace std;
long long n,a[10000],mmax,cnt,b[505][505],ggg;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	mmax=max(a[i],mmax);
    	ggg+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(2*mmax>=ggg){
			cout<<0;
	}
	if(n==3){
		if(2*mmax>=ggg){
			cout<<0;
		}
		else{
			cout<<1; 
		}
	}
	if(mmax=1){
		for(int i=1;i<=500;i++){
			b[1][i]=i;
			b[i][1]=1;
		}
		for(int i=2;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=1;k<=j-i+1;k++){
					b[i][j]+=b[i-1][j-k]%998;
				}
			}
		}
	for(int i=3;i<=n;i++){
		cnt+=b[i][n]%998;
	}
		cout<<cnt%998%244%353;
	}
	else{
		cout<<1;
	}
	return 0;
}