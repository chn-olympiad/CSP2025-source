#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int amx,h;
	int m1,m2,mm3;
}edge[100001];
int t;
bool cmp(node x,node y){
	return x.amx>y.amx;
}
int dfs(int x){
	int cnt=0;
	if(x==1){
		return cnt;
	}
	
	int k=0;
	for(int i=1;i<=3;i++){
		if(i==1){
			cnt+=edge[i].a;
		}
		if(i==2){
			cnt+=edge[i].b;
		}
		else{
			cnt+=edge[i].c;
		}
		int s=dfs(x--);
		k=max(s,k);
	}
	cnt+=k;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>edge[i].a>>edge[i].b>>edge[i].c;
			
		}
		int ans=dfs(n);
		
		cout<<ans<<endl;
		
	}
}
