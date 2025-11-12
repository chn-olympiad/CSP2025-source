#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
long long cnt;
bool s[100010];
int jk[110][2010];
void dfs(int l,int k,int mx,int q){
	if(l==k){
		if(q>mx*2){
			jk[mx][q]=1;
			return;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==0){
			s[i]=1;
			int maxx=mx,qz=q;
			if(mx<a[i]){
				maxx=a[i];
			}
			qz+=a[i];
			dfs(l+1,k,maxx,qz);
			s[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int mx=-1e6;
		int qqq=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			qqq+=a[i];
		}
		if(mx*2<qqq){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,0,0);
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=2000;j++){
			if(jk[i][j]==1){
				cnt++;
			}
		}
	}
	cout<<(cnt%998244353);
	return 0;
} 