#include<bits/stdc++.h> 
using namespace std;
int n,m,k;int ans=0;
struct road{
	int city2;
	int rc;
	int city1;
}r[1000006];
int cc[10004];
vector<road> city1[10004];

bool amp(road a,road b){
	return a.rc<b.rc;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int f,t,c;
	for(int i=0;i<m;i++){
		cin>>f>>t>>c;
//		road p;p.city2=t;p.rc=c;
//		city1[f].push_back(p);
//		p.city2=f;p.rc=c;
//		city1[t].push_back(p);
		r[i].city1=f;r[i].city2=t;r[i].rc=c;
	}
	sort(r,r+m,amp);
	for(int i=0;i<m;i++){
		f=r[i].city1;t=r[i].city2;c=r[i].rc;
		if(cc[f]==0 || cc[t]==0){
			ans+=c;
			cc[f]=1;cc[t]=1;
		}
	}
	cout<<ans;
	
}
