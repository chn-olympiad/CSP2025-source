//GZ-S00429 中天中学 赵行健 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e5+10;
int p[N*3],mx=-1,n;
vector<int> g[N*3];
void dfs(int u,int sum,int a,int b,int c){
//	cout<<u<<' ';
	if(u>n*3) return ;
	for(int v:g[u]){
		sum+=p[v];
//		cout<<u<<' '<<v<<' '<<sum<<endl;
		if((v%3==1&&a==n/2)||(v%3==2&&b==n/2)||(u%3==0&&c==n/2)){
			sum-=p[v];
			continue;
		}
		if(v%3==1) {
			a++;	
		}
		if(v%3==2) {
			b++;	
		}
		if(v%3==0) {
			c++;	
		}
//		cout<<a<<' '<<b<<' '<<c<<endl;
		if(sum>mx) mx=sum;
		dfs(v,sum,a,b,c);
		if(v%3==1) {
			a--;	
		}
		if(v%3==2) {
			b--;	
		}
		if(v%3==0) {
			c--;	
		}
		sum-=p[v];
	}
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	for(int i = 0;i<=N;i++){
		if(i%3==1) g[i].push_back(i+4),g[i].push_back(i+5),g[i].push_back(i+3);
		else if(i%3==2) g[i].push_back(i+2),g[i].push_back(i+3),g[i].push_back(i+4);
		else g[i].push_back(i+1),g[i].push_back(i+2),g[i].push_back(i+3);
	}
	while(T--){
		cin>>n;
		for(int i = 1;i<=N*3;i++) p[i]=0;
		for(int i = 1;i<=n*3;i++){
			cin>>p[i];
		}
		mx=-1;
		int sum=0,a=0,b=0,c=0;
		dfs(0,sum,a,b,c);
		cout<<mx<<endl;
	}
} 
//bool cmp(int a,int b){
//	return a>b;
//}
//signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	int T;cin>>T;
//	while(T--){
//		int n;cin>>n;
//		for(int i = 1;i<=n;i++){
//			int a1,a2,a3;cin>>a1>>a2>>a3;
//			p[i]=a1;
//		}
//		sort(p+1,p+n+1,cmp);
//		int ans=0;
//		for(int i = 1;i<=n/2;i++){
//			ans+=p[i];
//		}
//		cout<<ans<<endl;
//	}
//} 

//Ren5Jie4Di4Ling5%
