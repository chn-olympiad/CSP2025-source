#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
int t,a1[100005],a2[100005],a3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qwe=1;qwe<=t;qwe++){
		int n;
		cin>>n;
		long long maxn=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+n+1);
		for(int i=n;i>=n/2+1;i--){
			maxn+=a1[i];
		}
		if(qwe<t) cout<<maxn<<endl;
		else cout<<maxn;
	}
	return 0;
}
