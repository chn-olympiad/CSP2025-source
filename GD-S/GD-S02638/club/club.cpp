#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5],b[100005][5],d[100005],ans=0;
void dfs(int x,int sum,int c,int y,int z){
	if(sum+d[n]-d[x-1]<=ans) return ;
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}if(c+1<=n/2) dfs(x+1,sum+a[x][1],c+1,y,z);
	if(y+1<=n/2) dfs(x+1,sum+a[x][2],c,y+1,z);
	if(z+1<=n/2) dfs(x+1,sum+a[x][3],c,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int f=1;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2];
			if(a[i][1]>=a[i][2]){
				b[i][1]=a[i][1];
				b[i][2]=a[i][2];
			}else{
				b[i][1]=a[i][2];
				b[i][2]=a[i][1];
			}cin>>a[i][3];
			if(a[i][3]>b[i][2]){
				b[i][3]=b[i][2];
				if(a[i][3]>b[i][1]){
					b[i][2]=b[i][1];
					b[i][1]=a[i][3];
				}else b[i][2]=a[i][3];
			}else b[i][3]=a[i][3];
			d[i]=d[i-1]+b[i][1];
			if(a[i][2]+a[i][3]!=0) f=0;
		}if(f==1){
			int c[100005],cnt=0,sum=0;
			for(int i=1;i<=n;i++){
				c[++cnt]=a[i][1];
			}sort(c+1,c+n+1);
			for(int i=n;i>=(n-1)/2;i--) sum+=c[i];
			cout<<sum<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
