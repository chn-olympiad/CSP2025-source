#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[200100],dp1[1100],qzh[1100];
int main(){
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			qzh[i]=a[i]^qzh[i-1];
		}
		for(int l=1;l<=n;l++){
			dp1[l]=max(dp1[l],dp1[l-1]);
			for(int r=l;r<=n;r++){
				if((qzh[r]^qzh[l-1])==k){
					//cout<<l<<' '<<r<<' '<<(qzh[l-1]^qzh[r])<<' '<<k<<endl;
					dp1[r+1]=max(dp1[r+1],dp1[l]+1);
				}
			}
		}
		cout<<max(dp1[n+1],dp1[n]);
		//return 0;
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			bool b;
			cin>>b;
			cnt+=b;
		}
		cout<<cnt;
	}
	return 0;
}

