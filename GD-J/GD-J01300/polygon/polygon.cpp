#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],b[5005],sum;
bool f[5005];
void dbx(int l,int m){
	if(l==m){
		int s=0;
		for(int i=1;i<=m;i++){
			s+=f[i]*a[i];
			s%=mod;
		}
		if(s>(a[m]*2)){
			sum++;
			sum%=mod;
		}
		return;
	}
	f[l]=0;
	dbx(l+1,m);
	f[l]=1;
	dbx(l+1,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(b[i]>(a[i]*2)){
			f[i]=1;
			dbx(1,i);
		}
	}
	cout<<sum;
	
	return 0;
}
