#include<bits/stdc++.h>
using namespace std;
int t,n,a2[100010][3],b[100010],c[5],ans;//b为选没选，c为第i个社团有多少人 
struct info{
	int x,y,z;//x为是谁，y为好感度，z为对谁好感 
}a[300010];
bool cmp(info x,info y){
	return x.y>y.y;
}
void dfs(int x,int x1,int x2,int x3,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(x1<n/2)dfs(x+1,x1+1,x2,x3,sum+a2[x][1]);
	if(x2<n/2)dfs(x+1,x1,x2+1,x3,sum+a2[x][2]);
	if(x3<n/2)dfs(x+1,x1,x2,x3+1,sum+a2[x][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		 cin>>n;
		 int cnt=0;
		 for(int i=1;i<=n;i++){
		 	for(int j=1;j<=3;j++){
		 		int x; 
		 		scanf("%d",&a2[i][j]);
		 		cnt++;
				a[cnt].x=i;
				a[cnt].y=a2[i][j];
				a[cnt].z=j;
			}
		 }
		 if(n<=10){
		 	dfs(1,0,0,0,0);
		 	cout<<ans<<endl;
		 }else{
			n=cnt;
			sort(a+1,a+n+1,cmp);
		 	for(int i=1;i<=n;i++){
		 		if(b[a[i].x])continue;
				if(c[a[i].z]==n/6)continue;
				b[a[i].x]=1;
				c[a[i].z]++;
				ans+=a[i].y; 
		 	}
			cout<<ans<<endl;	 	
		 }
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		c[1]=c[2]=c[3]=0;
		ans=0;
	}
	return 0;
} 

