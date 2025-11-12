#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,ans,shu;
int c[4];
struct sun{
	long long a,b,c;
};
sun a[N];
void dfs(int step){
	if(step>n){
		ans=max(shu,ans);
		return;
	}
	if(c[1]<n/2){
		c[1]++;
		shu+=a[step].a;
		dfs(step+1);
		c[1]--;
		shu-=a[step].a;
	}
	if(c[2]<n/2){
		c[2]++;
		shu+=a[step].b;
		dfs(step+1);
		c[2]--;
		shu-=a[step].b;
	}
	if(c[3]<n/2){
		c[3]++;
		shu+=a[step].c;
		dfs(step+1);
		c[3]--;
		shu-=a[step].c;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=-1;shu=0;
		for(int i=1;i<=3;i++)
			c[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
