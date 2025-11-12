#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
scanf("%d",&t);
while(t--){
	int n;
	scanf("%d",&n);
	vector<vector<ll>> a(n,vector<ll>(3));
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	ll ans=0;
	int limit =n/2;
	for(int main_dept=0;main_dept<3;main_dept++){
		vector<pair<ll,int>>gains;
		ll base_sum=0;
		for(int i=0;i<n;i++){
		base_sum+=a[i][main_dept];
		ll gain1=a[i][(main_dept+1)%3]-a[i][main_dept];
		ll gain2=a[i][(main_dept+2)%3]-a[i][main_dept];
		}
		sort(gains.begin(),gains.end(),[](const pair<ll,int>&x,const pair<ll,int>&y){
			return x.first>y.first;
		});
		ll current=base_sum;
		int dept1_count=0,dept2_count=0;
		for(int i=0;i<n;i++){
			if(gains[i].first<=0)break;
			if(dept1_count<limit&&dept2_count<limit){
				current+=gains[i].first;
				int idx=gains[i].second;
				if(a[idx][(main_dept+1)%3]-a[idx][main_dept]>=a[idx][(main_dept+2)%3]-a[idx][main_dept]){
					dept1_count++;
				} else{
					dept2_count++;
				}
			}else if(dept1_count<limit){
				int idx=gains[i].second;
				ll gain=a[idx][(main_dept+1)%3]-a[idx][main_dept];
				if(gain>0){
					current+=gain;
					dept1_count++;
				}
			}else if(dept2_count<limit){
				int idx=gains[i].second;
				ll gain=a[idx][(main_dept+2)%3]-a[idx][main_dept];
				if (gain<0)  {
					current+=gain;
					dept2_count++;
				}
			}else{
				break;
			}
		}
		ans=max(ans,current);
	}
	printf("%lld\n",ans);
}
fclose(stdin);
fclose(stdout);
return 0;	
} 
