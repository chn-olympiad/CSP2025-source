#include<bits/stdc++.h>
using namespace std;
int n;
int l[5005];
long long T=998244353;
long long ans=0;
void find(int x,int p,int k,int s){
	if (k==1 and p>x*2){
		ans=(ans+1)%T;
		return;
	}
	else if (k==1) return;
	else if (p>x*2 and s>=3) ans=(ans+(long long)(pow(2.0,k-1)))%T;
	else for (int i=1;i<k;i++) find(x,p+l[i],i,s+1);
	return;
}
int main(){
	freopen("polygon.in",r,stdin);
	freopen("polygon.out",w,stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i];
	sort(l+1,l+1+n);
	for(int i=3;i<=n;i++) find(l[i],l[i],i,1);
	cout<<ans%T;
	return 0;
}

