#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
vector<int> a;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int n,k;
	cin>>n>>k;
	a.resize(n+1);
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt1++;
		else if(a[i]==0)cnt0++;
	}
//	cout<<cnt1<<" "<<cnt0<<"\n";
	if(cnt1==n){
		if(k==0)cout<<n/2<<"\n";
		else if(k==1)cout<<n<<"\n";
	}else if(cnt1+cnt0==n)cout<<cnt1<<"\n";
	else if(k==0)cout<<cnt0<<"\n";
	else {
		int ans=0;
		vector<int> pre(n+1);
		for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
		int ll=1,rr=n,flag=1;
		while(flag){
//			cout<<ll<<"\n";
			int tmp=INT_MAX;
			for(int i=ll;i<rr;i++){
				for(int j=i;j<=rr;j++){
					if((pre[j]^pre[i-1])==k){
						tmp=min(tmp,j+1);
					}
				}
			}
			if(tmp==INT_MAX)flag=0;
			else ans++,ll=tmp;
		}
		cout<<ans<<"\n";
	}
}
// 2 4 5 6 7

