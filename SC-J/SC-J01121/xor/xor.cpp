#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],qz[500010],lst,ans,cl[500010],cnt;
bool mp[10000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1,cl[++cnt]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		qz[i]=qz[i-1]^a[i];
//		cout<<qz[i]<<" ";
		if(mp[qz[i]^k]){
//			cout<<"\n"<<i<<"\n";
			ans++;
			while(cnt){
				mp[cl[cnt]]=0;
				cnt--;
			}
		}
		mp[qz[i]]=1;
		cl[++cnt]=qz[i];
	}
	cout<<ans;
	return 0;
}
/*
4 0
2 1 0 3
*/