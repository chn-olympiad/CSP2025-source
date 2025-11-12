#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
vector<int>p[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<10;i++)p[i].clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				p[1].push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=a[i][2];
				p[2].push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			}
			else{
				ans+=a[i][3];
				p[3].push_back(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
			}
		}
		sort(p[1].begin(),p[1].end());
		sort(p[2].begin(),p[2].end());
		sort(p[3].begin(),p[3].end());
		//cout<<p[1].size()<<" "<<p[2].size()<<" "<<n<<endl;
		if(p[1].size()>n/2){
			int t=p[1].size();
			for(int j=0;t>n/2;j++){
				t--;
				ans-=p[1][j];
			}
		}
		if(p[2].size()>n/2){
			int t=p[2].size();
			for(int j=0;t>n/2;j++){
				t--;
				ans-=p[2][j];
			}
		}
		if(p[3].size()>n/2){
			int t=p[3].size();
			for(int j=0;t>n/2;j++){
				t--;
				ans-=p[3][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
