#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z,sumx,sumy,sumz;
}a[100010];
int cmp(node xx,node yy){
	if(xx.x!=yy.x) return xx.x>yy.x;
	else if(xx.y!=yy.y) return xx.y>yy.y;
	else return xx.z>yy.z;
}
bool vis[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		long long n,ansx=0,ansy=0,ansz=0,res=0;
		vis[1]=vis[2]=vis[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		a[1].sumx=a[1].x,a[1].sumy=a[1].y,a[1].sumz=a[1].z;
		for(int i=2;i<=n;i++){
			a[i].sumx=a[i-1].sumx+a[i].x;
			a[i].sumy=a[i-1].sumy+a[i].y;
			a[i].sumz=a[i-1].sumz+a[i].z; 
		}
		for(int i=1;i<=n;i++){
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x){
				if(vis[1]){
					if(max(a[i].y,a[i].z)==a[i].y){
						if(vis[2]) res+=a[i].z,ansz++;
						else res+=a[i].y,ansy++;
					}else if(max(a[i].y,a[i].z)==a[i].z){
						if(vis[3]) res+=a[i].y,ansy++;
						else res+=a[i].y,ansy++;
					}
				}else res+=a[i].x,ansx++;
			}else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y){
				if(vis[2]){
					if(max(a[i].x,a[i].z)==a[i].x){
						if(vis[1]) res+=a[i].z,ansz++;
						else res+=a[i].x,ansx++;
					}else if(max(a[i].x,a[i].z)==a[i].z){
						if(vis[3]) res+=a[i].y,ansy++;
						else res+=a[i].x,ansx++;
					}
				}else res+=a[i].y,ansy++;
			}else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].z){
				if(vis[3]){
					if(max(a[i].x,a[i].y)==a[i].x){
						if(vis[1]) res+=a[i].y,ansy++;
						else res+=a[i].x,ansx++;
					}else if(max(a[i].x,a[i].y)==a[i].y){
						if(vis[2]) res+=a[i].x,ansx++;
						else res+=a[i].y,ansy++;
					}
				}else res+=a[i].z,ansz++;
			}
			if(ansx==n/2) vis[1]=1;
			if(ansy==n/2) vis[2]=1;
			if(ansz==n/2) vis[3]=1; 
			//cout<<ansx<<" "<<ansy<<" "<<ansz<<endl; 
		}
		cout<<res<<endl; 
	}
	return 0;
} 
