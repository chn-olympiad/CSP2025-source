#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,a[100005][5],ans;
vector<int> v[4];
void sl(){
	cin>>n;
	ans=0;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int x=max({a[i][1],a[i][2],a[i][3]});
		ans+=x;
		if(a[i][1]==x){
			sort(a[i]+1,a[i]+1+3);
			v[1].push_back(x-a[i][2]);
		}
		else if(a[i][2]==x){
			sort(a[i]+1,a[i]+1+3);
			v[2].push_back(x-a[i][2]);
		}
		else if(a[i][3]==x){
			sort(a[i]+1,a[i]+1+3);
			v[3].push_back(x-a[i][2]);
		}
	}
	if(v[1].size()>n/2){
		sort(v[1].begin(),v[1].end());
		int len=v[1].size();
		int z=len,id=0;
		while(z>n/2){
			ans-=v[1][id++];
			z--;
		}
	}
	else if(v[2].size()>n/2){
		sort(v[2].begin(),v[2].end());
		int len=v[2].size();
		int z=len,id=0;
		while(z>n/2){
			ans-=v[2][id++];
			z--;
		}
	}
	else if(v[3].size()>n/2){
		sort(v[3].begin(),v[3].end());
		int len=v[3].size();
		int z=len,id=0;
		while(z>n/2){
			ans-=v[3][id++];
			z--;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)sl();
	return 0;
} 
/*
15:10 想到idea 
15:25 过大样例 
*/
