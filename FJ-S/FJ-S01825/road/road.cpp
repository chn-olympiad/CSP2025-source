#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
struct node{
	int y;
	long long w;
	int e;
}; 
vector<node> s[N]; 
int n,m,k,mm;
bool d[N];
long long yu[11],uu[N];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long gg;
	cin>>n>>m>>k;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y>>gg;
		s[x].push_back({y,gg,0});
		s[y].push_back({x,gg,0});
	}
	for(int i=1;i<=k;i++){
		cin>>yu[i];
		for(int j=1;j<=n;j++){
			cin>>uu[j];
			for(int k=1;k<=j-1;k++){
				s[j].push_back({k,uu[j]+uu[k],i});
				s[k].push_back({j,uu[j]+uu[k],i});
			}
		}
	}
	int tot=1;
	while(mm<n-1){
		mm++;
		d[tot]=1;
		long long ww=1000000009;
		int yy=1,ee=0;
		for(int i=0;i<(int)s[tot].size();i++){
			node f=s[tot][i];
			if(!d[f.y]){
				if(ww>f.w+yu[f.e]){
					yy=f.y;
					ww=f.w+yu[f.e];
					ee=f.e;
				}	
			}
		}
		yu[ee]=0;
		d[ee]=1;
		ans+=ww;
		tot=yy;
	}
	cout<<ans<<endl;
	return 0;
}
