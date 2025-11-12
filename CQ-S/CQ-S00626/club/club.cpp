#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N][4],n;
vector<int> id[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=3;i++)id[i].clear();
		for(int i=1;i<=n;i++){
			int maxx=0,pos=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxx){
					maxx=a[i][j];
					pos=j;
				}
			}
			id[pos].push_back(i);
			ans+=maxx;
		}
		for(int i=1;i<=3;i++)
			if(id[i].size()>n/2){
				vector<int> val;
				for(auto v:id[i]){
					if(i==1)val.push_back(a[v][1]-max(a[v][2],a[v][3]));
					if(i==2)val.push_back(a[v][2]-max(a[v][1],a[v][3]));
					if(i==3)val.push_back(a[v][3]-max(a[v][2],a[v][1]));
				}
				sort(val.begin(),val.end());
				for(int j=0;j<val.size()-n/2;j++)ans-=val[j];
			}
		cout<<ans<<endl;
	}
	return 0;
}
