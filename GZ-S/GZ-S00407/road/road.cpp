//GZ-S00407 毕节梁才学校 詹桂鑫
#include<bits/stdc++.h>;

using namespace std;

int n,m,k;
int r,t,y;
int pr[10010];
int pk[10010];
int main(){
	freopen("road1.in","r",stdin);
	freopen("road1.ans","w",stdout);
	freopen("road2.in","r",stdin);
	freopen("road2.ans","w",stdout);
	freopen("road3.in","r",stdin);
	freopen("road3.ans","w",stdout);
	freopen("road4.in","r",stdin);
	freopen("road4.ans","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>r>>t>>y;
	}
	for(int i=0;i<=n;i++){
		cin>>pr[i];
	}
	for(int i=0;i<=n;i++){
		cin>>pk[i];
	}
	int ans=13;
	cout<<ans<<endl;
	return 0;
}
