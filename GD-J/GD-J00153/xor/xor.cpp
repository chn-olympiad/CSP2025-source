#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],l,r,sum,ll[500005],rr[500005],ans;
map<int,int>f;
bool pd;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)pd=1;
		ll[i]=a[i]^ll[i-1];
		f[ll[i]]=i;
		r=ll[i]^m;
		if((f[r]>=l&&a[i]!=0)||(a[i]^m)==0){
			ans++;
			l=i+1;
			ll[i]=0;
		}
	}if(pd==1){
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==m)ans++;
		}
	}
	cout<<ans;
}
//2 (1) (1 6) (1 6 3)
