#include<bits/stdc++.h>
using namespace std;
int t; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	 
	cin>>t;
	while(t>=1){
		t--;
		int n; cin>>n;
		int a[n+1][4];
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++){
			a[j][0]=0;
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		if(n==2){
			int ans=0;
			for(int i=1;i<=2;i++){
				for(int j=1;j<=3;j++){
					if(i==j) continue;
					if(i!=j){
						ans=max(ans,a[1][i]+a[2][j]);
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}else{
			int num[4],ans=0;
			memset(num,0,sizeof(num));
			vector<int> v[n+1];
			for(int i=1;i<=n;i++){
				int x=max(max(a[i][1],a[i][2]),a[i][3]);
				for(int j=1;j<=3;j++){
					if(a[i][j]==x){
						num[j]++;
						v[j].push_back(x);
						ans+=a[i][j];
					}
				}
			}
			for(int i=1;i<=3;i++){
				if(num[i]>n/2){
					sort(v[i].begin(),v[i].begin()+v[i].size());
					int l=0;
					while(1){
						if(num[i]==n/2)break;
						num[i]--;
						ans=ans-v[i][l];
						l++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
	
