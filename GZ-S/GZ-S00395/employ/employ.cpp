//GZ-S00395 贵阳市第十八中 蒙昊锐 
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	long long cnt=n;
	for(int i=1;i<=m;i++){
		ans*=cnt;
		cnt--;
	}
	cout<<ans<<endl;
	return 0;
}
