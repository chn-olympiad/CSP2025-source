#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,ans;
int a[MAXN];
int f[MAXN],sum[MAXN],p[MAXN];
map<int,queue<int> > mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
//		cout<<sum[i]<<endl;
		mp[sum[i]].push(i);
	}
	for(int i=1;i<=n;i++){
		int p=sum[i-1]^k;
//		cout<<mp[p].front()<<" "<<p<<endl;
		while(!mp[p].empty()){
			int x=mp[p].front();
			if(x<i){
				mp[p].pop();
				continue;
			}
			f[i]=x;
			break;
		}
		if(!f[i]) f[i]=n+1;
//		cout<<f[i]<<endl;
	}
	p[n+1]=1e9;
	for(int i=n;i>=1;i--){
		p[i]=min(p[i+1],f[i]);
//		cout<<p[i]<<" ";
	}
	int i=1;
	while(i<=n){
		i=p[i]+1;
		if(i==n+2) break;
//		if(i==n+2) break;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*

*/
