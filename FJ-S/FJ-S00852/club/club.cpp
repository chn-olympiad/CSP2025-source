#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct member{int id,x;}a[3][N];
inline bool cmp(member x,member y){
	return x.x>y.x;
}
int t,n,t1,t2,t3,ans;bool v[N]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--){
		t1=t2=t3=ans=0;memset(v,0,sizeof(v));cin>>n;
		for(int i=1;i<=n;i++){
			a[0][i].id=a[1][i].id=a[2][i].id=i;
			cin>>a[0][i].x>>a[1][i].x>>a[2][i].x;
		}
		sort(a[0]+1,a[0]+n+1,cmp);
		sort(a[1]+1,a[1]+n+1,cmp);
		sort(a[2]+1,a[2]+n+1,cmp);
		for(int i=1;i<n;i++){
			while(v[a[0][t1].id])t1++;
			while(v[a[1][t2].id])t2++;
			while(v[a[2][t3].id])t3++;
			if(a[1][t2].x>a[0][t1].x){
				if(a[2][t3].x>a[1][t2].x)v[a[2][t3].id]=1,ans+=a[2][t3].x;
				else v[a[1][t2].id]=1,ans+=a[1][t2].x;
			}else{
				if(a[2][t3].x>a[0][t1].x)v[a[2][t3].id]=1,ans+=a[2][t3].x;
				else v[a[0][t1].id]=1,ans+=a[0][t1].x;
			}
		}
		cout<<ans<<'\n';
	}
}
