#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000001],s[10000001],sum,ans,js[10000001],xx,yy;
void solve(int y){
	for(int i=xx;i<=yy;i++){
		if(js[i]==1)
			return;
	}
	for(int i=xx;i<=yy;i++){
		if(sum==0)
			sum=s[i];
		else	
			sum=sum^s[i];
	}
	if(sum==k){
		for(int i=xx;i<=yy;i++)
			js[i]=1;
		ans++;
	}
	sum=0;
}
void abc(int x){
	for(int i=x;i<=n;i++){
		xx=i-x+1;
		yy=i;
  		for(int j=xx;j<=yy;j++){
			s[j]=a[j];
		}
		solve(x);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		abc(i);
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

*/
