#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
#define mod 998244353
int n;
int a[N];
int mpre[5][N];//pre[1][i]前缀和 pre[2][i]最大值
int res;
//dp 但是我不会
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mpre[1][i]=mpre[1][i-1]+a[i];
		mpre[2][i]=max(mpre[2][i-1],a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			int p=mpre[1][r]-mpre[1][l-1];
			int m=mpre[2][r];
			if(r-l>=2&&p>2*m){
				//cout<<l<<' '<<r<<"\n";
				//cout<<"m:"<<m<<"p:"<<p<<"\n";
				res++;
			}
		}
	}
	cout<<res%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
