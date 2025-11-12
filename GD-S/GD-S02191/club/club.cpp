#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5+5;
int T,n,ans,a[N][5];
vector<int> t[5];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=3;i++)t[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				t[1].push_back(max(a[i][2],a[i][3])-a[i][1]);
				ans+=a[i][1];
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				t[2].push_back(max(a[i][1],a[i][3])-a[i][2]);
				ans+=a[i][2];
			}else{
				t[3].push_back(max(a[i][1],a[i][2])-a[i][3]);
				ans+=a[i][3];
			}
		}
		for(int i=1;i<=3;i++){
			if((int)(t[i].size())>n/2){
				sort(t[i].begin(),t[i].end(),cmp);
				for(int j=0;j<(int)(t[i].size())-n/2;j++)ans+=t[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
