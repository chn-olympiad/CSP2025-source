#include<bits/stdc++.h>
using namespace std;
int n,ans=0,cnt,xxor;
long long a[500001],k,jilu[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	for(int i=2,x;i<=n;i++) cin>>x,a[i]=(a[i-1] ^ x);
	for(int i=1;i<=n;i++) jilu[i]=-1;
	for(int i=n,r;i>=1;i--){
		cnt=0;
		r=i;
		for(int l=r;l>=1;){
			if(l==1) xxor=a[r];
			else xxor=(a[l-1] ^ a[r]);
			l--;
			if(xxor==k){
				cnt++;
				jilu[r]=max(jilu[r],cnt*1ll);
				r=l;
				if(jilu[r]!=-1){
					cnt+=jilu[r];
					break;
				}
			}
		}
		ans=max(ans,cnt);
	} 
	cout<<ans;
	return 0;
}
