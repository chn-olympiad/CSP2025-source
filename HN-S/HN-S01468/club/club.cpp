#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}cl[N];
int T,n,ans,s,a1,b1,c1;
void dfs(int x){
	if((a1>(n/2))||(b1>(n/2))||(c1>(n/2)))return;
	if(x>n){
		if(s>ans){
			ans=s;
			return;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			s+=cl[x].a,a1++;
			dfs(x+1);
			a1--,s-=cl[x].a;
		}
		if(i==2){
			s+=cl[x].b,b1++;
			dfs(x+1);
			b1--,s-=cl[x].b;
		}
		if(i==3){
			s+=cl[x].c,c1++;
			dfs(x+1);
			c1--,s-=cl[x].c;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(cl,0,sizeof(cl));
		cin>>n;
		for(int i=0;i<n;i++)cin>>cl[i].a>>cl[i].b>>cl[i].c;
		dfs(0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
