#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t,n[6],a1[20020],a2[20020],a3[20020];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int b=1;b<=t;++b){
		cin>>n[b];
		for(int i=1;i<=n[b];++i){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		int ans1,ans2,ans3,ans4,ans5,ans6,ans;
		ans1=a1[1]+a2[2];
		ans2=a1[1]+a3[2];
		ans3=a2[1]+a1[2];
		ans4=a2[1]+a3[2];
		ans5=a3[1]+a1[2];
		ans6=a3[1]+a2[2];
		ans=max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
		cout<<ans<<endl;
		
		



	
	
	}
	return 0;
}
	

