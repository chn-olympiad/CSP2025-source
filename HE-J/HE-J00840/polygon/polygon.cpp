#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n;
int a[5005];
int l,r,maxn=INT_MIN;
long long s=0,z=0;
void solve(){
	for(int j=l;j<=r;j++){
		s+=a[j];
		maxn=max(maxn,a[j]);	
	}
	if(s>maxn*2){
		z++;
	}
	l++;
	r++;
	maxn=INT_MIN;
	s=0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3){
		printf("%d",0);
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			printf("%d",1);
			return 0;
		}
		else{
			printf("%d",0);
			return 0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		l=1;
		r=i;
		while(r!=n){
			solve();
		}
	}
	cout<<z%mod;
	return 0;
}
