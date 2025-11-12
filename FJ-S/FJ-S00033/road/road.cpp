#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[11];
bool v[100001];
long long s[100001],ans;
int o[11][10001],x,y,z;
vector < pair < int , int > > ve[100001];
priority_queue < pair < int , int > , vector < pair < int , int > > , greater< pair < int , int > > > q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	for(int i=1;i<=n;i++){
		s[i]=LLONG_MAX;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&z);
		ve[x].push_back({y,z});
		ve[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&o[i][j]);
		}
	}
	q.push({0,1});
	s[1]=0;
	while(!q.empty()){
		if(q.top().first>s[q.top().second]){
			q.pop();
			continue;
		}
		for(auto i:ve[q.top().second]){
			if(s[i.first]>i.second){
				s[i.first]=i.second;
				if(v[i.first])v[i.first]=0;
				q.push({s[i.first],i.second});
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=k;j++){
				if((v[j]&&o[j][q.top().second]+o[j][i]<s[i])||(v[j]==0&&a[j]+o[j][q.top().second]+o[j][i]<=s[i])){
					s[i]=o[j][i]+o[j][q.top().second];
					v[j]=1;
					q.push({s[i],i});
				}
			}
		}
		q.pop();
	}
	for(int i=1;i<=n;i++){
		ans+=s[i];
	}
	for(int i=1;i<=k;i++){
		if(v[i])ans+=a[i];
	}
	cout<<ans;
	return 0;
}
