#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[500010];
int tot[500010],id[500010];
int q[(1<<21)];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot[i]=tot[i-1]^a[i];
	}
	int l=-1,ans=0;
	memset(q,-1,sizeof(q));
	q[k]=0;
	for(int i=1;i<=n;i++){
		if((~q[tot[i]])&&q[tot[i]]>=l){
				ans++;
				l=i;
				q[tot[i]]=-1;
		}
			q[tot[i]^k]=i;
	}
	cout<<ans;
	return 0;
}
