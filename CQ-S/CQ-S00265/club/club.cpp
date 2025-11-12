#include <bits/stdc++.h>
using namespace std;
long long mx,mx2,mx3,t,n,ans,a[100005][3];
vector<int> v[3];
bool cmp(int x,int y){
	long long m1=1e18,m2=1e18;
	for(int i=0;i<3;i++) if(i!=mx) m1=min(m1,a[x][mx]-a[x][i]),m2=min(m2,a[y][mx]-a[y][i]);
    return m1<m2;
}
int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0);
    cout.tie(0); 
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);  
    cin>>t;
    while(t--){
    	cin>>n,mx=mx2=-1,ans=0,v[0].clear(),v[1].clear(),v[2].clear();
    	for(int i=1;i<=n;i++){
    		cin>>a[i][0]>>a[i][1]>>a[i][2];
    		if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]) ans+=a[i][0],v[0].push_back(i);
    		else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]) ans+=a[i][1],v[1].push_back(i);
		    else ans+=a[i][2],v[2].push_back(i);
		}
		if(v[0].size()>n/2) mx=0;
		if(v[1].size()>n/2) mx=1;
		if(v[2].size()>n/2) mx=2;
		if(mx>=0){
			stable_sort(v[mx].begin(),v[mx].end(),cmp);
			int k=0;
		    for(int i=0;v[mx].size()-i>n/2;i++){
		    	k=i+1;
		    	if(mx!=0 && (mx==1 || a[v[mx][i]][mx]-a[v[mx][i]][0]<=a[v[mx][i]][mx]-a[v[mx][i]][1]) && (mx==2 || a[v[mx][i]][mx]-a[v[mx][i]][0]<=a[v[mx][i]][mx]-a[v[mx][i]][2])) ans-=a[v[mx][i]][mx]-a[v[mx][i]][0],v[0].push_back(v[mx][i]);
			    else if(mx!=1 && (mx==0 || a[v[mx][i]][mx]-a[v[mx][i]][1]<=a[v[mx][i]][mx]-a[v[mx][i]][0]) && (mx==2 || a[v[mx][i]][mx]-a[v[mx][i]][1]<=a[v[mx][i]][mx]-a[v[mx][i]][2])) ans-=a[v[mx][i]][mx]-a[v[mx][i]][1],v[1].push_back(v[mx][i]);
			    else ans-=a[v[mx][i]][mx]-a[v[mx][i]][2],v[2].push_back(v[mx][i]);
			}
	    	if(v[0].size()>n/2 && mx!=0) mx2=0;
	    	if(v[1].size()>n/2 && mx!=1) mx2=1;
	    	if(v[2].size()>n/2 && mx!=2) mx2=2;	
	    	if(mx2>=0){
	    		for(int i=0;i<3;i++) if(mx!=i && mx2!=i) mx3=i;
	    		long long minn=1e18;
	    		for(int i=k;i<v[mx].size();i++) minn=min(minn,a[v[mx][i]][mx]-a[v[mx][i]][mx3]);
			    for(int i=0;i<v[mx2].size();i++) minn=min(minn,a[v[mx2][i]][mx2]-a[v[mx2][i]][mx3]);
			    ans-=minn;
			}
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
