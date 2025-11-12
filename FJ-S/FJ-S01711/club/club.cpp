#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5][100005];
int b[5];
bool book[5][100005];
int c[100005],d[100005];
int t,n;
ll ans,sum;
bool tsxza,tsxzb;
void dfs(int x){
	for(int i=1;i<=3;i++){
		if(b[i]>(n/2)){
			return;
		}
	}
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		sum+=a[i][x];
		b[i]++;
		dfs(x+1);
		b[i]--;
		sum-=a[i][x];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			c[i]=a[1][i];
			d[i]=a[2][i];
			if(a[2][i]!=0){
				tsxza=1;
			}
			if(a[3][i]!=0){
				tsxza=1;
				tsxzb=1;
			}
		}
		if(tsxza==0){
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2+1;i++)
			{
				ans+=c[i];
			}
			cout<<ans<<"\n";
			return 0;
		}
		sum=0;
		ans=0;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
} 
