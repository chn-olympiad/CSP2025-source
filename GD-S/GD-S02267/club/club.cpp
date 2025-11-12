#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
int a[N][4];
int p[4];
long long ans;
int r=3;
void dfs(int x,int step){
	if(x>n){
		if(ans<=step) ans=step;
		return ;
	}
	for(int i=1;i<=r;i++){
		if(p[i]>=(n/2)) continue;
		p[i]++;
		dfs(x+1,step+a[x][i]);
		p[i]--;
	}
	
}
int tong[N];
struct node{
	int a,b;
};
int cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		node e[N];
		int a1=0,a2=0,a3=0;		
		memset(p,0,sizeof p);
		memset(tong,0,sizeof tong);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]); 
				tong[a[i][j]]++;
			}
			e[i].a=a[i][1];
			e[i].b=a[i][2];
			a1=max(a1,a[i][1]);
			a2=max(a2,a[i][2]);
			a3=max(a3,a[i][3]);
		}
		if(a1!=0&&a2==0&&a3==0){
			int o=n/2;
			for(int j=20000;j>=0;j--){
				if(tong[j]&&o){
					if(tong[j]<=o){
						ans+=j*tong[j];
						o-=tong[j];
					}else{
						ans+=j*o;
						o=0;
					}
				}
			}
			cout<<ans<<endl;
		}else if(a1!=0&&a2!=0&&a3==0){
				sort(e+1,e+n+1,cmp);
				for(int i=1;i<=n/2;i++) ans+=e[i].a;
				for(int i=n/2+1;i<=n;i++) ans+=e[i].b;
				cout<<ans<<endl;
		}else{
			r=3;
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
