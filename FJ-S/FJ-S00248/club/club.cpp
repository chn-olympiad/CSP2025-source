#include<bits/stdc++.h>
using namespace std;
#define ll long long
//rerecycyclcle
//god club
struct node{
	int id,x;
}a1[100100],a2[100100],a3[100100];
int t,n,ans;
bool a2b,a3b;
void dfs(int sum,int one,int two,int thr,int stp){
	if(stp>n){
		ans=max(ans,sum);
		return;
	}
	if((one+1)<=(n/2))dfs(sum+a1[stp].x,one+1,two,thr,stp+1);
	if((two+1)<=(n/2))dfs(sum+a2[stp].x,one,two+1,thr,stp+1);
	if((thr+1)<=(n/2))dfs(sum+a3[stp].x,one,two,thr+1,stp+1);
}
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		a3b=a2b=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i].x>>a2[i].x>>a3[i].x;
			a1[i].id=a2[i].id=a3[i].id=i;
			if(a3[i].x!=0){
				a3b=0;
			}
			if(a2[i].x!=0){
				a2b=0;
			}
		}
		ans=0;
		if(a3b&&a2b){
			sort(a1+1,a1+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a1[i].x;
			}
			cout<<ans<<endl;
		}
		else if(n<=30){
			dfs(0,0,0,0,1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
