#include<bits/stdc++.h>
using namespace std;
int t,n,a[100007][4],sum;
vector<int> vec[4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n;sum=0;
    	vec[1].clear();vec[2].clear();vec[3].clear();
    	for(int i=1;i<=n;i++){
    		cin>>a[i][1]>>a[i][2]>>a[i][3];
    		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
    			sum+=a[i][1];
    			vec[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
    			sum+=a[i][2];
    			vec[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
    			sum+=a[i][3];
    			vec[3].push_back(a[i][3]-max(a[i][1],a[i][2]));
			}
		}
		if(vec[1].size()>n/2){
			sort(vec[1].begin(),vec[1].end());
			for(int i=0;i<vec[1].size()-n/2;i++) sum-=vec[1][i];
		}
		else if(vec[2].size()>n/2){
			sort(vec[2].begin(),vec[2].end());
			for(int i=0;i<vec[2].size()-n/2;i++) sum-=vec[2][i];
		}
		else if(vec[3].size()>n/2){
			sort(vec[3].begin(),vec[3].end());
			for(int i=0;i<vec[3].size()-n/2;i++) sum-=vec[3][i];
		}
    	cout<<sum<<'\n';
	}
	return 0;
}
//ezt1 30min
