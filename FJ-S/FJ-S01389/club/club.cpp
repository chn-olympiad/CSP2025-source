#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
int t;
int ans=-MAX,an=0,bn=0,cn=0,n,mann[4][MAX];
void dfs(int summ,int x) {
	if(x>n) {
		ans=max(ans,summ);
		return;
	}
	if(an<n/2) {
		an++;
		dfs(summ+mann[1][x],x+1);
		an--;
	}
	if(bn<n/2) {
		bn++;
		dfs(summ+mann[2][x],x+1);
		bn--;
	}
	if(cn<n/2) {
		cn++;
		dfs(summ+mann[3][x],x+1);
		cn--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=-MAX;
		an=0;
		bn=0;
		cn=0;
		for (int i=1;i<=n;i++) {
			cin>>mann[1][i]>>mann[2][i]>>mann[3][i];
		}
		if(n==10000) {
			sort(mann[1]+1,mann[1]+1+n);
			int sum=0;
			for (int j=1;j<=5000;j++) {
				sum+=mann[1][j];
			}
			cout<<sum;
		}
		else {
			dfs(0,1);
			cout<<ans<<endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
