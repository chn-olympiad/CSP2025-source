#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+50,N1=1e3+10;
int a[N],ans;
int n,k;
int b[N1][N1];
struct S{
	int i,j;
}s[N1*N1];
void dfs(int i,int cnt) {
	if(i==n+1) {
		ans=max(ans,cnt);
		return;
	}
	for(int h=i;h<=n;h++) {
		for(int g=h;g<=n;g++) {
			if(b[h][g]==k) {
				dfs(g+1,cnt+1);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if(k==0) {
		for(int i=1;i<=n;i++) {
			if(a[i]==0) ans++;
			else if(a[i]==a[i+1]&&i<n) {
				ans++;
				i++;
			}
		}
		cout<<ans;
	}else if(k==1) {
		for(int i=1;i<=n;i++) {
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}else {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			int t=0;
			for(int j=i;j<=n;j++){
				t^=a[j];
				b[i][j]=t;
				if(t==k) {
					s[++cnt]={i,j};	
				}
			}
		}
		sort(s+1,s+cnt+1,[](S x,S y){if(x.j==y.j) return x.i<y.i; return x.j<y.j;});
		int last=0;
		for(int i=1;i<=cnt;i++) {
			if(s[i].i>last){
				ans++;
				last=s[i].j;
			}
		}
		cout<<ans;
	}
	
	return 0;
}