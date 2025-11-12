#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;
const int N = 1e5+10;
int n,a[4][N];
int f[4][N],sum;

void dfs(int i,int num,int c1,int c2,int c3){
	if(i==n+1){
		sum = max(num,sum);
		return;
	}
	if(c1>=n/2){
		dfs(i+1,num+a[2][i],c1,c2+1,c3);
		dfs(i+1,num+a[3][i],c1,c2,c3+1);
		dfs(i+1,num-a[1][i-1]+a[1][i],c1,c2,c3);
	}
	else if(c2>=n/2){
		dfs(i+1,num+a[1][i],c1+1,c2,c3);
		dfs(i+1,num+a[3][i],c1,c2,c3+1);
		dfs(i+1,num-a[2][i-1]+a[2][i],c1,c2,c3);
	}
	else if(c3>=n/2){
		dfs(i+1,num+a[1][i],c1+1,c2,c3);
		dfs(i+1,num+a[2][i],c1,c2+1,c3);
		dfs(i+1,num-a[3][i-1]+a[3][i],c1,c2,c3);
	}
	else {
		dfs(i+1,num+a[1][i],c1+1,c2,c3);
		dfs(i+1,num+a[2][i],c1,c2+1,c3);
		dfs(i+1,num+a[3][i],c1,c2,c3+1);
	}
}

void solve(){
	scanf("%d",&n);
	int fa = 1,fb = 1;
	for(int i =1 ;i<=n;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i];
		if(a[2][i]!=a[3][i] && a[2][i]!=0) fa = 0;
		if(a[3][i]!=0) fb = 0;
	}
	if(n<=30){
		sum = 0;
		dfs(1,0,0,0,0);
		cout<<sum<<endl;
	}
	else {
		if(fa){
			int ae[n+2];
			for(int i = 1;i<=n;i++){
				ae[i] = a[1][i];
			}
			sort(ae+1,ae+n+1);
			int sum = 0;
			for(int i = n;i>=n/2;i--){
				sum+=ae[i];
			}
			cout<<sum<<endl;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
