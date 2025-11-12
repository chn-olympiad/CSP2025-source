#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
}dis[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>dis[i].a>>dis[i].b>>dis[i].c;
			ans+=max(dis[i].a,max(dis[i].b,dis[i].c));
		}
		for(int i=1;i<=n;i++){
			
		}
	}
	return 0;
}
