#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,temp=0,ans=0,last=0;
map <int,int> mp,st;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
//	mp[0]=1;
//	st[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		temp^=x;
//		cout<<temp<<' '<<(k^temp)<<'\n';
//		cout<<i<<':'<<temp<<'\n';
		if(x==k){
//			cout<<x<<' '<<i<<'\n';
			last=i;
			ans++;
			temp=0;
			continue;
		}
		if(temp==k){
//			cout<<temp<<' '<<i<<'\n';
			last=i;
			ans++;
			temp=0;
			continue;
		}
		if(mp[k^temp]&&st[k^temp]>last){
//			cout<<st[k^temp]<<' '<<i<<'\n';
			last=i;
			ans++;
			temp=0;
		}
		mp[temp]++;
		st[temp]=i;
	}
	cout<<ans;
	return 0;
}
