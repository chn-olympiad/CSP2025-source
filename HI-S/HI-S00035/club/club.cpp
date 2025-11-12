#include <bits/stdc++.h>
using namespace std;

int n,m,a[100010][100010];
bool vis[100010][100010];
int total;
int mx = -1;

void dfs(int pos){
	if(pos==4){
		long long sum=0,a1=0,a2=0,a3=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=3;j++){
				sum+=a[i][j]*vis[i][j];
			}
			a1+=a[i][1]*vis[i][1];
			a2+=a[i][2]*vis[i][2];
			a3+=a[i][3]*vis[i][3];
		}
		if(sum>mx&&a1<=total&&a2<=total&&a3<=total) mx = sum;
		return;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=1;j++){
			vis[i][pos] = j;
			dfs(pos+1);
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> n;
	total = n/2;
	for(int i=1;i<=n;i++){
		cin >> m;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=3;k++) cin >> a[j][k];
		}
		dfs(1);
	}
	
	
	cout << mx;	

	return 0;
}
