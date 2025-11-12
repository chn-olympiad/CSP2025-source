#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mt=998244353;
ll s=0;
int n;
int _ns[5005],ns;
ll sm[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&_ns[i]);
	}sort(_ns+1,_ns+1+n);
	sm[0]=1;
	for(int i=1;i<=n;i++){
		ns=_ns[i];
		for(int j=ns+1;j<=5001;j++){
			s+=sm[j];
			s%=mt;
		}
		sm[5001]*=2;
		sm[5001]%=mt;
		for(int j=5000;j>=5000-ns+1;j--){
			sm[5001]+=sm[j];
			sm[5001]%=mt;
		}
		for(int j=5000-ns;j>=0;j--){
			sm[j+ns]+=sm[j];
			sm[j+ns]%=mt;
		}
	}printf("%lld",s);
	return 0;
}
