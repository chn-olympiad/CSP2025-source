#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sa[5005],k1=0,s[25050025],kk=0;
bool b[25050025];
long long C(int n,int a){
	int cc=abs(n-a);
	long long sum=1,sum1=1;
	for(int i=max(cc,a)+1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	for(int i=min(cc,a);i>=1;i--){
		sum1*=i;
		sum1%=998244353;
	}
	return sum/sum1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool aa=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) aa=0;
	}
	if(n<3){
		cout<<"0\n";
		return 0;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[n]*2<a[1]+a[2]+a[3]) cout<<1<<"\n";
		else cout<<"0\n";
		return 0; 
	}
	int ans=0;
	if(aa){
		for(int i=4;i<=n;i++){
			ans+=C(i,n);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
