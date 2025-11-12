#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1105;
int t,n;
struct node{
	int x,y,z;
};
node a[N];
bool cmp1(node k,node q){
	if(k.x==q.x) return k.y>q.y;
	return k.x>q.x;
}
bool cmp2(node k,node q){
	if(k.y==q.y) return k.x>q.x;
	return k.y>q.y;
}
bool cmp3(node k,node q){
	if(k.z==q.z) return k.x>q.x;
	return k.z>q.z;
}
int f[N],g[N],l1[N],l2[N],p[N],hj[10],u[N];
long long m=0,ans=0,k=0;
void dfs(int v,int deep){
	if(deep>n) {
		for(int i=1;i<=n;i++){
			if(hj[i]>n/2){
				return ;
			}
		}
		for(int j=1;j<=n;j++){
			k+=u[j];
			//cout<<u[j]<<endl;
		}
		ans=max(ans,k);
		k=0;
		//cout<<ans<<endl;
		return;
	}
	
	hj[v]++;
	if(v==1) u[deep]=a[deep].x;
	if(v==2) u[deep]=a[deep].y;
	if(v==3) u[deep]=a[deep].z;
	for(int j=1;j<=3;j++){
		dfs(j,deep+1);
	}
	hj[v]--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		cin >>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin >>a[i].x>>a[i].y>>a[i].z;
		}
		if((a[1].y==0&&a[1].z==0)&&(a[2].y==0&&a[2].z==0)&&(a[3].y==0&&a[3].z==0)&&(a[4].y==0&&a[4].z==0)&&(a[5].y==0&&a[5].z==0)){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
		}
		else if(n<=10){
			k=0;
			for(int i=1;i<=n;i++){
				u[i]=0;
				hj[i]=0;
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=n;j++){
					u[j]=hj[j]=0;
				}
				k=0;
				dfs(i,1);
			}
		}
		else{
		for(int i=1;i<=n;i++){
			f[i]=g[i]=l1[i]=l2[i]=p[i]=0;
		}
		m=0;
		sort(a+1,a+n+1,cmp1);
		f[0]=0;
		g[0]=0;
		l1[0]=0;
		l2[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]+a[i].x;
			g[i]=g[i-1]+max(a[i].y,a[i].z);
			if(a[i].y>a[i].z) l1[i]++;
			else if(a[i].y<a[i].z) l2[i]++;
			else p[i]++;
			l1[i]+=l1[i-1];
			l2[i]+=l2[i-1];
			p[i]+=p[i-1];
		}
		for(int i=1;i<=n/2;i++){
			m=f[i]+g[n]-g[i];
			if(l1[n]-l1[i]>n/2||l2[n]-l2[i]>n/2) m=0;
			if(m>ans) ans=m;
			}
		for(int i=1;i<=n;i++){
			f[i]=g[i]=l1[i]=l2[i]=p[i]=0;
		}
		m=0;
		sort(a+1,a+n+1,cmp2);
		f[0]=0;
		g[0]=0;
		l1[0]=0;
		l2[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]+a[i].y;
			g[i]=g[i-1]+max(a[i].x,a[i].z);
			if(a[i].x>a[i].z) l1[i]++;
			else if(a[i].x<a[i].z) l2[i]++;
			else p[i]++;
			l1[i]+=l1[i-1];
			l2[i]+=l2[i-1];
			p[i]+=p[i-1];
		}
		for(int i=1;i<=n/2;i++){
			m=f[i]+g[n]-g[i];
			if(l1[n]-l1[i]>n/2||l2[n]-l2[i]>n/2) m=0;
			if(m>ans) ans=m;
			}
		for(int i=1;i<=n;i++){
			f[i]=g[i]=l1[i]=l2[i]=p[i]=0;
		}
		m=0;
		sort(a+1,a+n+1,cmp3);
		f[0]=0;
		g[0]=0;
		l1[0]=0;
		l2[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]+a[i].z;
			g[i]=g[i-1]+max(a[i].x,a[i].y);
			if(a[i].x>a[i].y) l1[i]++;
			else if(a[i].x<a[i].y) l2[i]++;
			else p[i]++;
			l1[i]+=l1[i-1];
			l2[i]+=l2[i-1];
			p[i]+=p[i-1];
		}
		for(int i=1;i<=n/2;i++){
			m=f[i]+g[n]-g[i];
			if(l1[n]-l1[i]>n/2||l2[n]-l2[i]>n/2) m=0;
			if(m>ans) ans=m;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

