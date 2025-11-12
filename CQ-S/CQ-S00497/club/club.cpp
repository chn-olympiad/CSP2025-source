#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T;
int n;
struct Node{
	int x,y,z;
};
Node a[N];
bool cmp(Node a,Node b){return a.x>b.x;}
bool cmq(Node a,Node b){return max(a.x,a.y)>max(b.x,b.y);}
long long ans;
void dfs(long long i,int l,int r1,int r2,int r3){
	if(l>n){
		ans=max(ans,i);
		return ;
	}
	if(r1<n/2) dfs(i+a[l].x,l+1,r1+1,r2,r3);
	if(r2<n/2) dfs(i+a[l].y,l+1,r1,r2+1,r3);
	if(r3<n/2) dfs(i+a[l].z,l+1,r1,r2,r3+1);
}
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i].y!=0||a[i].z!=0){
				flag=0;  
				break;
			}
		}
		ans=0;
		if(flag){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<"\n";
			continue;
		}
		flag=1;
		for(int i=1;i<=n;i++){
			if(a[i].z!=0){
				flag=0;  
				break;
			}
		}
		ans=0;
		if(flag){
			sort(a+1,a+n+1,cmq);
			int r1=0,r2=0;
			for(int i=1;i<=n;i++){
				if(r1==n/2){
					r2++;
					ans+=a[i].y;
				}
				else if(r2==n/2){
					r1++;
					ans+=a[i].x;
				}
				else if(a[i].x>a[i].y){
					r1++;
					ans+=a[i].x;
				}
				else{
					r2++;
					ans+=a[i].y;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(0,1,0,0,0);
		cout<<ans<<"\n";
	}

	return 0;
}

