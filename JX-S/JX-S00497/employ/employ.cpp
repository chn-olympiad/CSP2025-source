#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n,m,a[1000],nn,ans;
string s;
long long gcd(long long x,long long y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	nn=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			nn--;
		}
	}
	n=nn;
	long long fz=1,fm=1,cnt=n+1;
	for(int i=1;i<=m;i++){
		cnt--;
		fz*=cnt;
		fm*=i;
		long long xx=gcd(fz,fm);
		if(xx!=1){
			fz/=xx;
			fm/=xx;
		}
	}
	ans=fz/fm;
	ans%=N;
	cout<<ans;
	return 0;
}
