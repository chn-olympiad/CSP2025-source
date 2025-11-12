#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10,M=998244353;
long long m,n,r,cnt=0,cnt1=0;
bool p1,p2,p3,p4,p5,p6;
long long a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			p1=1;
		}
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]<a[3]){
			cout<<0;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	if(!p1){
		for(int i=3;i<=n;i++){
			cnt=1;
			for(int j=1;j<=i;j++){
				cnt=(cnt%M*(n-j+1)%M)%M;
			}
			cnt1=(cnt1%M+cnt%M)%M;
		}
	}
	cout<<cnt1;
	return 0;
}
