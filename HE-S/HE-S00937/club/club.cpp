#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
bool vis[100005];
int t,n,fy,fz;
long long ansx,ansy,res;
bool cmp(node xx,node yy){
	if(xx.x==yy.x)return xx.y<yy.y;
	return xx.x>yy.x; 
}
bool cnp(node xx,node yy){
	if(xx.y==yy.y)return xx.x<yy.x;
	return xx.y>yy.y;
}
void dfs(long long man,int suma,int sumb,int sumc){
	//cout<<man<<" "<<suma<<" "<<sumb<<" "<<sumc<<endl;
	res=max(res,man);
	if(suma>n/2||sumb>n/2||sumc>n/2||suma+sumb+sumc>=n)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(suma<n/2){
				dfs(man+a[i].x,suma+1,sumb,sumc);
			}
			if(sumb<n/2){
				dfs(man+a[i].y,suma,sumb+1,sumc);
			}
			if(sumc<n/2){
				dfs(man+a[i].z,suma,sumb,sumc+1);
			}	
			vis[i]=0;
		}
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ansx=0;
		ansy=0;
		fy=0;
		fz=0;
		res=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
			vis[i]=0;
			if(a[i].y!=0)fy=1;
			if(a[i].z!=0)fz=1;
		}
		if(fy==0&&fz==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ansx+=a[i].x;
			}
			cout<<ansx<<endl;
		}else{
			if(fz==0){
				sort(a+1,a+n+1,cmp);
			
				for(int i=1;i<=n/2;i++){
					ansx+=a[i].x;
				}
				for(int i=n/2+1;i<=n;i++){
					ansx+=a[i].y;
				}
				sort(a+1,a+n+1,cnp);
				
				for(int i=1;i<=n/2;i++){
					ansy+=a[i].y;
				}
				for(int i=n/2+1;i<=n;i++){
					ansy+=a[i].x;
				}
				cout<<max(ansx,ansy)<<endl;
			}else{
				dfs(0,0,0,0);
				cout<<res<<endl;
			}
		}
	}
	return 0;
} 



