#include<bits/stdc++.h>
using namespace std;

struct student{
	int c[4];
};
student a[100005];
long long mx=-1;
int now[4];
int n;
void dfs(int deep,long long sum){
	if(deep==n+1){
		mx=max(sum,mx);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(now[i]<n/2){
			now[i]++;
			dfs(deep+1,sum+a[deep].c[i]);
			now[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];	
		}
		dfs(1,0);
		cout<<mx<<'\n';
		mx=-1;	
	}
	return 0;
}
