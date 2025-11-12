#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long s[3];
};
const int N=1e5+10;
node a[N];
long long mx=0;
long long ret[N];
void dfs(int now,int x,int y,int z){
	if(x>n/2||y>n/2||z>n/2){
		return;
	}
	if(now>n){
		long long sum=0;
		for(int i=1;i<=n;i++){
		//	cout<<ret[i]<<' ';
			sum+=ret[i];
		}
		//cout<<endl;
		//cout<<sum<<endl;
		mx=max(mx,sum);
		return;
	}
	ret[now]=a[now].s[0];
	dfs(now+1,x+1,y,z);
	ret[now]=a[now].s[1];
	dfs(now+1,x,y+1,z);
	ret[now]=a[now].s[2];
	dfs(now+1,x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		mx=0;
		cin>>n;
		//cout<<n<<endl;
		for(int i=1;i<=n;i++){
			cin>>a[i].s[0]>>a[i].s[1]>>a[i].s[2];
		}
		dfs(1,0,0,0);
		cout<<mx<<endl;
	}
	
	return 0;
}
