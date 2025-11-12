#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,sr[N],ans;
bool val[1<<21];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		sr[i]=sr[i-1]^x;
	}
	int lst=0;
	val[0]=1;
	for(int i=1;i<=n;i++){
		if(val[k^sr[i]]){
			for(int j=lst;j<=i-1;j++) val[sr[j]]=0;
			lst=i;
			ans++;
		}
		val[sr[i]]=1;
	}
	cout<<ans;
	return 0;
}

