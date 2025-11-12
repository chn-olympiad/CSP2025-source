#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
struct node{
	int w,xu,club;
};
int n,t;
node a[N];
int vis[N];
int ans=0;
bool cmp(node a,node b){
	if(a.w == b.w) return a.xu < b.xu;
	return a.w > b.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		int c1=0,c2=0,c3=0;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n*3;i+=3){
			cin>>a[i].w>>a[i+1].w>>a[i+2].w;
			a[i].club=1;
			a[i+1].club=2;
			a[i+2].club=3;
			a[i].xu=a[i+1].xu=a[i+2].xu=i;
		}
		sort(a+1,a+1+3*n,cmp);
		for(int i=1;i<=3*n;i++){
			if(!vis[a[i].xu]){//如果该同学未加入社团 
				vis[a[i].xu]=1;
				if(a[i].club == 1){
					if(c1 < n/2){
						c1++;
						ans+=a[i].w; 
					}
					else{
						vis[a[i].xu]=0;
					}
				}
				if(a[i].club == 2){
					if(c2 < n/2){
						c2++;
						ans+=a[i].w; 
					}
					else{
						vis[a[i].xu]=0;
					}
				}
				if(a[i].club == 3){
					if(c3 < n/2){
						c3++;
						ans+=a[i].w; 
					}
					else{
						vis[a[i].xu]=0;
					}
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
