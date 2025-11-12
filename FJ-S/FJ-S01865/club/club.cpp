#include <iostream>
using namespace std;
int a[100010][3],cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;
	while(T--){
		cnt[0]=cnt[1]=cnt[2]=0;
		int n,res=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++){
			int mx=max(a[i][0],max(a[i][1],a[i][2]));
			if(mx==a[i][0])cnt[0]++;
			else if(mx==a[i][1])cnt[1]++;
			else cnt[2]++;
			res+=mx;
		}
//		if(cnt[0]>n/2){
//			
//		}else if(cnt[1]>n/2){
//			
//		}else if(cnt[2]>n/2){
//			
//		}else{
			cout<<res<<'\n';
//		}
	}
}
