#include<bits/stdc++.h>
using namespace std;
int x[5001],xx[5001];
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x,x+n);
	xx[0]=0;
	x[0]=0;
	for(int i=1;i<=n;i++){
		xx[i]=xx[i-1]+x[i];
	}
	for(int i=1;i<=n;i++){
		for(int ii=0;ii<i;ii++){
			if(xx[i]-xx[ii]>x[i]*2){
				ans++;
				for(int k=ii+2;k<i;k++){
					if(xx[i]-xx[ii]-x[k]>x[i]*2){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
}

