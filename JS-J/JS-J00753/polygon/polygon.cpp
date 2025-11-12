#include<bits/stdc++.h>
using namespace std;
int n,a[5005],vis[5005];
long long MOD=998244353;
long long czh(int dn,int up){
	long long sss=1;
	for(int i=dn;i<=up;++i){
		sss*=i;
		sss%=MOD;
	}
	for(int i=2;i<=up-dn;++i){
		sss/=i;
		sss%=MOD;
	}
	return sss;
}
int main(void){
	//freopen
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))){
			cout<<1<<endl;
			return 0;
		}
		cout<<0<<endl;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;++i){
		if(i==3){
			ans+=1;
		}
		else{
			for(int j=1;j<=i-3;++j){
				ans+=czh(j,i);
				ans%=MOD;
			}
			ans++;
		}ans%=MOD;
	}
	return 0;
}
//#1-3,#15-20,kenenghuiguafen.10:27 ok
