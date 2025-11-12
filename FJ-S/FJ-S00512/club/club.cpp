#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][4],b[100005];bool A=1;bool B=1;
int dfs(int p,int aa,int bb,int cc){
	int anst=0;
	if(aa<=(n/2)+1){anst=max(anst,dfs(p+1,aa+1,bb,cc)+a[p+1][1]);}
	if(bb<=(n/2)+1){anst=max(anst,dfs(p+1,aa,bb+1,cc)+a[p+1][2]);}
	if(cc<=(n/2)+1){anst=max(anst,dfs(p+1,aa,bb,cc+1)+a[p+1][3]);}
	return anst;
}
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2] || a[i][3]) A=0;
			if(a[i][3]) B=0;
		}
		if(A){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			cout<<b[n]+b[n-1];
		}
		else if(n==2){
			int t=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						t=max(t,a[1][i]+a[2][j]);
					}
				}
			}
			cout<<t;
		}
		else{
			cout<<dfs(0,0,0,0);
		}
		cout<<'\n';
	}
	return 0;
}
