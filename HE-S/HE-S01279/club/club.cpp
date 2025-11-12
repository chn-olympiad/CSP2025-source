#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long a[1145141][10];
struct Node{
	long long num,id;
	operator<(const Node& a)const{return num>a.num;}
};
Node b[11451411];
long long ans;
void dfs(int x,int f,int s,int t,long long sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(f<n/2){
		dfs(x+1,f+1,s,t,sum+a[x][1]);
	}
	if(s<n/2){
		dfs(x+1,f,s+1,t,sum+a[x][2]);
	}
	if(t<n/2){
		dfs(x+1,f,s,t+1,sum+a[x][3]);
	}
}
int ze;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
			if(a[i][2]||a[i][3]){
				ze=1;
			} 
		}
		if(ze){
			dfs(1,0,0,0,0);
		}
		else{
			for(int i=1;i<=n;i++){
				b[i].num=a[i][1];
				b[i].id=i;
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++){
				ans+=b[i].num;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
