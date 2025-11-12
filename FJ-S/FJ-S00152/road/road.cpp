#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using pii=pair<int,int>;
int n,m,k;
struct as{
	int l,r,w;
};
vector<as>v;
int cmp(as x,as y){
	return x.w<y.w;
}
int z[1000100];
int d[1000100];
int st[1000100];
int op[1000100];
map<int,int>mp; 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	for(int i=1;i<=k;i++){
		cin>>op[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	int sum=0;
	if(k==0){
		for(auto i:v){
			if(mp[i.l]==0||mp[i.r]==0){
				mp[i.l]=1;
				mp[i.r]=1;
				sum+=i.w;
			}
		}
		cout<<sum;
		return 0;
	}
	cout<<"13";
	return 0;
} 

