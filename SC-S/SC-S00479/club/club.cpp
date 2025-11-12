#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],s[4],ans;
vector<int>v[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		s[1]=s[2]=s[3]=ans=0;
		v[1].clear();
		v[2].clear();
		v[3].clear();
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				v[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
				s[1]++;
			}
			else if(a[i][2]>=a[i][3]){
				ans+=a[i][2];
				v[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
				s[2]++;
			}
			else{
				ans+=a[i][3];
				v[3].push_back(a[i][3]-max(a[i][1],a[i][2]));
				s[3]++;
			}
		}
		for(int i=1;i<=3;i++){
			if(s[i]>n/2){
				sort(v[i].begin(),v[i].end());
				for(int j=0;j<s[i]-n/2;j++){
					ans-=v[i][j];
				}
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}