#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,a[5001],qzh[5001][5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i][1]=a[i];
	}
	sort(a+1,a+n+1);
	for(int l=1;l<=n;l++){
		for(int r=2;r<=n;r++)qzh[l][r]=qzh[l][r-1]+a[r];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(qzh[i][j]>a[j]*2){
				ans++;
				ans%=998244353;
			}else if(j-i>2){
				for(int k=i+1;k<j;k++){
					if(qzh[i][j]-a[k]>a[j]*2){
						ans++;
						ans%=998244353;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}