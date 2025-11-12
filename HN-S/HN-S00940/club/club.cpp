#include <bits/stdc++.h>
using namespace std;
long long t,n,ans=-1e9; 
struct node{
	long long f1,f2,f3;
}a[100005];
long long x_n[100005],y_n[100005],z_n[100005],n_n[100005];
void dfs(int x,int y,int z,long long num){
	if(x+y+z<=n){
		for(int i=1;i<=n;i++){
		if(x+1<=n/2&&x_n[i]==0&&n_n[i]==0){
			x_n[i]=1;
			n_n[i]=1;
			//printf("dfs(%d+1,%d,%d,num+=a[%d].f1)",&x,&y,&z,&num);
			//cout<<"dfs("<<x<<"+1,"<<y<<","<<z<<","<<"num:"<<num<<"+="<<"a["<<i<<"].f1)"<<endl;
			dfs(x+1,y,z,num+a[i].f1);
			x_n[i]=0;
			n_n[i]=0;
		}
		if(y+1<=n/2&&y_n[i]==0&&n_n[i]==0){
			y_n[i]=1;
			n_n[i]=1;
			//cout<<"dfs("<<x<<","<<y<<"+1,"<<z<<","<<"num:"<<num<<"+="<<"a["<<i<<"].f2)"<<endl;
			dfs(x,y+1,z,num+a[i].f2);
			y_n[i]=0;
			n_n[i]=0;	
		}
		if(z+1<=n/2&&z_n[i]==0&&n_n[i]==0){
			z_n[i]=1;
			n_n[i]=1;
			//cout<<"dfs("<<x<<","<<y<<","<<z<<"+1,"<<"num:"<<num<<"+="<<"a["<<i<<"].f3)"<<endl;
			dfs(x,y,z+1,num+a[i].f3);
			z_n[i]=0;
			n_n[i]=0;
		}
	}
	//cout<<x<<" "<<y<<" "<<z<<" "<<num<<endl;
	ans=max(ans,num);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){ 
		ans=-1e9;
		memset(a,0,sizeof(a));
		memset(x_n,0,sizeof(x_n));
		memset(y_n,0,sizeof(y_n));
		memset(z_n,0,sizeof(z_n));
		memset(z_n,0,sizeof(n_n));
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].f1>>a[j].f2>>a[j].f3;
		}
		//cout<<endl;
		dfs(0,0,0,0);
		//cout<<endl;
		cout<<ans<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

