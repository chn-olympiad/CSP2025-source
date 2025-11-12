#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int a[1005];
int a1[1005];
int priz[1005];
int g[1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i]>>a1[i]>>priz[i];
	}for(int j=0;j<k;j++){
		cin>>g[j];
		for(int l=0;l<n;l++){
			cin>>a[l+m];
		}
	}for(int j=0;j<rand()%k;j++){
		ans+=priz[rand()%n];
	}ans+=g[rand()%k];
	cout<<ans;
	return 0;
}
