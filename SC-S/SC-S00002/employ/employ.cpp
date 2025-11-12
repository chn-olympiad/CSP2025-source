#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n) m=1;
	else if(m*2>n) m=n-m;
	int nn=n;
	long long ans=0,cnt=1,chu=0;
	for(int i=m;i<=n;i++){
		for(int j=1;j<=m;j++){
			cnt*=nn;
			nn-=1;
			if(chu!=0) chu*=chu+1;
			else chu=1;
			cnt%=998244353;
		}
		ans+=cnt/chu;
		cnt%=998244353;
		cnt=1;
		chu=0;
		nn=n;
	}
	cout<<ans;
}