#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int a[100005];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m,cnt=0;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) cnt++;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans*=i;ans%=mod;
	}
	cout<<ans;
	cout<<endl;
	return 0;
}
/*
0xAF0=2800
	AFO
	lg 657210
	2021/12/31 --- 2025/11/1
	
	i think its bc of too much florr xd		
			
			

	  ##########		############        ##########
   	##			##		## 				  ##		  ##
    ##			##		##				  ##		  ##
	##			##		##				  ##		  ##
	##			##		##				  ##		  ##
	##			##		##				  ##		  ##
	 ###########		##########		  ##		  ##
	##			##		##				  ##		  ##
	##			##		##				  ##		  ##
	##			##		##				  ##		  ##
	##			##		##				  ##		  ##
	##			##		##				  ##		  ##
	##			##		##				    ##########	  																																					

*/
