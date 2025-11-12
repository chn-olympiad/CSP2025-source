#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int at,bt,ct,d[10009],c[1000009],f[10009];
struct dot{
	int next,w;
};
bool cm(dot a,dot b){
	return a.w<b.w;
}
vector<dot> a[10009];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		c[i+1]=t3;
		a[t1].push_back({t2,t3});
		a[t2].push_back({t1,t3});
	}
	for(int i=0;i<m;i++){
		int p,t;
		cin>>p;
		for(int j=0;j<n;j++){
			cin>>t;
		}
	}
	for(int j=0;j<n;j++){
				sort(a[j],a[j].end(),cm);
			}
	sort(c+1,c+n+1);
	a[0]=-999999;
	for(int i=1;i<=m;i++){
		if(a[i]!=a[i-1]){
			for(int j=0;j<n;j++){
				sort(a[j],a[j]+n,cmp);
				
			
			}
		}
	}
	cout<<ans;
	return 0;
}
