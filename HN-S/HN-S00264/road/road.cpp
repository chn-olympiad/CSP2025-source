#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
vector<int> c;
int a[10001][10001]={-1};
int b[11][10001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int s,e;
		cin>>s>>e;
		cin>>a[s][e];
		a[e][s]=a[s][e];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	if(k==0){
		c.push_back(1);
		int num=0;
		num++;
		int ans=0;
		while(num<n){
			int x,y,min_1;
			for(int i:c){
				for(int j=1;j<n;j++){
					if(i==j)break;
					if(a[i][j]==-1)continue;
					if(a[i][j]<min_1){
						x=i;y=j;
						min_1=a[i][j];
					}
				}
			}
			for(int i:c){
				a[i][y]=-1;
				a[y][i]=-1;
			}
			c.push_back(y);
			ans+=min_1;
			num++;
		}
		cout<<ans;
	}
	return 0;
}
