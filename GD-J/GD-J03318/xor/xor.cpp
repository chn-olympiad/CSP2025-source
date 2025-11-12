#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],qian[500005],ans;
bool f=1;
set<pair<int,int> > l1r1;
set<pair<int,int> > l2r2;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]!=1) f=0;
		}
		if(f){
			cout<<n/2;
			return 0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			qian[i]=qian[i-1]^a[i];
		}
	}
	for(int l1=1;l1<n;l1++){
		for(int r1=l1;r1<n;r1++){
			for(int l2=r1+1;l2<=n;l2++){
				for(int r2=l2;r2<=n;r2++){
					if((qian[r1]^qian[l1-1])==k) l1r1.insert({l1,r1});
					if((qian[r2]^qian[l2-1])==k) l2r2.insert({l2,r2});
				}
			}
		}
	}
	cout<<l1r1.size()+l2r2.size();
	return 0;
}
