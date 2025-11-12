#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+5;
int t,n,a[maxn][5],sum;
vector<ll> v[5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		v[1].clear();
		v[2].clear();
		v[3].clear();
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3]){
				sum+=a[i][1];
				v[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
			}else  if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3]){
				sum+=a[i][2];
				v[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
			}else{
				sum+=a[i][3];
				v[3].push_back(a[i][3]-max(a[i][2],a[i][1]));
			}
		}
		//cout<<sum<<endl;
		if(v[1].size()>n/2){
			sort(v[1].begin(),v[1].end());			
			for(int i=0;i<(v[1].size()-n/2);i++) sum-=v[1][i];
		}
		if(v[2].size()>n/2){
			sort(v[2].begin(),v[2].end());			
			for(int i=0;i<(v[2].size()-n/2);i++) sum-=v[2][i];
		}
		if(v[3].size()>n/2){
			sort(v[3].begin(),v[3].end());			
			for(int i=0;i<(v[3].size()-n/2);i++) sum-=v[3][i];
		}
		cout<<sum<<'\n';
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
4 0 0*/
