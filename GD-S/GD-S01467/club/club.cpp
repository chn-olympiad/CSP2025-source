#include<bits/stdc++.h>
using namespace std;
int T;
int a[100005][3];
int maxn[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(a,0,sizeof a);
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			maxn[i]=max(a[i][0],max(a[i][1],a[i][2]));
		}
		sort(maxn+1,maxn+1+n);
		for(int i=n;i>ceil(n/2.0);i--){
			ans+=maxn[i];
		} 
		cout<<ans<<endl;
	}
	return 0;
} 
