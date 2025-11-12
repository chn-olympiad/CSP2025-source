//GZ-S00476 贵阳新世界学校 陈睿泽 
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(long long i=n-m;i<=n;i++){
    	long long t=1;
    	for(long long j=0;j<m;j++) t=t*(n-j);
		ans+=t; 
	}
	cout<<ans%998244353;
	return 0;
}





