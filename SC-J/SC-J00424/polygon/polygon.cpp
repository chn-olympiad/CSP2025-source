#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum,mmax=-1,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];sum+=a[i];
		mmax=max(mmax,a[i]);
	}
	mmax*=2;
	if(sum>mmax){
		cout<<1<<endl;
		return 0;
	}
	return 0;
}