#include<bits/stdc++.h>
using namespace std;
int t,n,nu[4],p,ans,d;
int a[100005][4];
vector<int> di[4];
bool flag;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++){
			nu[i]=0; di[i].clear();
		} 
		ans=0;flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p=1;
			if(a[i][p]<a[i][2]) p=2;
			if(a[i][p]<a[i][3]) p=3;
			nu[p]++;
			ans+=a[i][p];d=1000000000;
			for(int j=1;j<=3;j++){
				if(j!=p) d=min(d,a[i][p]-a[i][j]); 
			}
			di[p].push_back(d);
		}
		for(p=1;p<=3;p++){
			if(nu[p]>n/2) {
				flag=1;break;
			}
		}
		if(flag==0) {
			cout<<ans<<"\n";
		}
		else{
			sort(di[p].begin(),di[p].end());
			for(int i=0;i<nu[p]-n/2;i++){
				ans-=di[p][i];
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
} 
