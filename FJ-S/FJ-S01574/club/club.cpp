#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef pair<int,int> PII;
int n;
int sum;
int so[N];
int a[N][4];
int s[4];
void dfs(int step,int cnt){
	if(step==n+1){
		sum=max(sum,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		if(s[i]+1<=n/2){
			s[i]++;
			dfs(step+1,cnt+a[step][i]);
			s[i]--;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		int flag=1;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(!(a[i][2]==0&&a[i][3]==0)){
				flag=0;
			}
			so[i]=a[i][1];
		}
		if(flag){
			sort(so+1,so+n+1);
			int sum=0;
			for(int i=n;i>=1.0*n/2;i--)	{
				sum+=so[i];
			}
			cout<<sum<<'\n';
			return 0;
		}
		sum=0;
		dfs(1,0);
		cout<<sum<<'\n';
	}
	return 0;
}

