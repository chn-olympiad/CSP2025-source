#include<bits/stdc++.h>
using namespace std;
int n,k,a[10010];
int ans;
struct N{
	int x,y;
}u[10010];
bool cmp(N a,N b){
	return a.x<=a.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int ns=a[i];
		for(int j=i;j<=n;j++){
			int m=a[j],p=0,q=0;
			while(max(ns,m)){
				p=p<<1;
				if((ns&m)%2==0 && (ns|m)%2)p+=1;
				else p=p<<1;
				m=m>>1;
				ns=ns>>1;
			}
			while(p){
				if((p&1)%2)q+=1;
				else q=q<<1;
				p=p>>1;
			}
			if(k==q){
				u[++ans].x=i;
				u[ans].y=j;
			}
			ns=q;
		}
	}
	int d=0;
	sort(u+1,u+ans+1,cmp);
	for(int i=1;i<ans;i++){
		for(int j=i+1;j<=ans;j++){
			if(u[i].y>=u[j].x)d--;
		}
	}
	cout<<ans+d;
	return 0;
}
