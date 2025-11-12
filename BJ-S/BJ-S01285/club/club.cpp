#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int a1,a2,a3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		vector<int> sum[5];
		int n;
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a1>>a2>>a3;
			int maxx=max(a1,max(a2,a3));
			ans+=maxx;
			if(a1==maxx){
				sum[1].push_back(maxx-max(a2,a3));
			}else if(a2==maxx){
				sum[2].push_back(maxx-max(a1,a3));
			}else if(a3==maxx){
				sum[3].push_back(maxx-max(a2,a1));
			}
		}
		if((int)sum[1].size()>n/2){
			sort(sum[1].begin(),sum[1].end());
			int num=sum[1].size()-n/2;
			for(int i=0;i<num;++i){
				ans-=sum[1][i];
			}
		}else if((int)sum[2].size()>n/2){
			sort(sum[2].begin(),sum[2].end());
			int num=sum[2].size()-n/2;
			for(int i=0;i<num;++i){
				ans-=sum[2][i];
			}
		}else if((int)sum[3].size()>n/2){
			sort(sum[3].begin(),sum[3].end());
			int num=sum[3].size()-n/2;
			for(int i=0;i<num;++i){
				ans-=sum[3][i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
