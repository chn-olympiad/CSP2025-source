#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100010;
int t,n,s[4];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v[3];
		ans=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>b&&a>c) v[0].push_back(max(b,c)-a);
			else if(b>c) v[1].push_back(max(a,c)-b);
			else v[2].push_back(max(a,b)-c);
			ans+=max(max(a,b),c);
		}
		int id=-1;
		for(int i=0;i<3;i++){
			if((int)(v[i].size())>(n/2)){
				id=i;
				break;
			}
		}
		if(id==-1){
			cout<<ans<<endl;
			continue;
		}
		sort(v[id].begin(),v[id].end());
		reverse(v[id].begin(),v[id].end());
		int kk=v[id].size()-(n/2);
		for(int i=0;i<kk;i++) ans+=v[id][i];
		cout<<ans<<endl;
	}
	return 0;
}
