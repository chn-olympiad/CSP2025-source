#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a1[N],a2[N],a3[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	bool vis=1,vis2=1;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0){
				vis=0;
			}
		}
		ans=0;
		if(vis){
			sort(a1+1,a1+1+n);
			for(int i=n;i>n/2;i--){
				ans+=a1[i];
			}
		}else{
			for(int i=1;i<=n;i++){
				int maxn=max(a1[i],a2[i]);
				ans+=max(maxn,a3[i]);
			}
		}
		cout<<ans;
	}
	return 0;
} 
