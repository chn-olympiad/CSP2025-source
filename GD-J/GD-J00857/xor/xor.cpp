#include<bits/stdc++.h>
#define int long long
using namespace std;

bool flag=true;
const int maxn=1e4+5;
int a[maxn];
int s;
int n,k,ans,cnt;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			flag=false;
	}
	if(flag&&k==0){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s=cnt=0;
		for(int j=i;j<=n;j++){
			s=(s^a[j]);
			if(s==k){
				cnt++;
				s=0;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
