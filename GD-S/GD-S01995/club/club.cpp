#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,a[N][4],an[4],ans,num,n;
void dfs(int k){
	if(k>n){
		ans=max(ans,num);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(an[i]<n/2){
			an[i]++,num+=a[k][i];
			dfs(k+1);
			an[i]--,num-=a[k][i];
		}
	}
}
void qmain(){
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	ans=0,num=0;
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
		qmain();
	return 0;
} 
