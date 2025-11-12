#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n;
struct node{
	int a1,a2,a3,sum;
}a[N];
int sump[10],f[N];
long long ans=0ll;
void dfs(int step,long long sum){
	if(step==n+1){
		ans=max(ans,sum);
		return;
	}
	if(sump[1]<n/2){
		sump[1]++;
		dfs(step+1,a[step].a1+sum);		
		sump[1]--;
	}
	if(sump[2]<n/2){
		sump[2]++;
		dfs(step+1,a[step].a2+sum);		
		sump[2]--;
	}
	if(sump[3]<n/2){
		sump[3]++;
		dfs(step+1,a[step].a3+sum);		
		sump[3]--;
	}
	return;
}
bool cmp(node p,node q){
	return p.a1>q.a1;
}
bool check1(){
	for(int i=1;i<=n;i++)
		if(a[i].a2!=0||a[i].a3!=0)
			return false;
	return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0ll;
		sump[1]=sump[2]=sump[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		if(n<=30)
			dfs(1,0ll);
		else if(check1()){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].a1;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
