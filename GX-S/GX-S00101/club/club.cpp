#include<bits/stdc++.h>
using namespace std;
int t,ans;
struct stu{int a,b,c;}s[100010];
int re[502][502][502];
//int re[100010][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		int n;cin>>n;
		memset(re,0,sizeof(re));
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)re[i][j][k]=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		for(int x=0;x<=n;x++)
		for(int y=0;y<=n;y++)
		for(int z=0;z<=n;z++)
		{
			if(x+y+z>n)break;
			if(x<n/2)re[x+1][y][z]=max(re[x+1][y][z],re[x][y][z]+s[x+y+z+1].a);
			if(y<n/2)re[x][y+1][z]=max(re[x][y+1][z],re[x][y][z]+s[x+y+z+1].b);
			if(z<n/2)re[x][y][z+1]=max(re[x][y][z+1],re[x][y][z]+s[x+y+z+1].c);
		}
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)
		ans=max(ans,re[i][j][k]);
		cout<<ans<<endl;
		/*
		for(int i=0;i<=n-1;i++){
			if(re[i][1]<n/2&&re[i+1][0]<re[i][0]+s[i+1].a)re[i+1][0]=re[i][0]+s[i+1].a,re[i+1][1]=re[i][1]+1,re[i+1][2]=re[i][2],re[i+1][3]=re[i][3];
			if(re[i][2]<n/2&&re[i+1][0]<re[i][0]+s[i+1].b)re[i+1][0]=re[i][0]+s[i+1].b,re[i+1][2]=re[i][2]+1,re[i+1][1]=re[i][1],re[i+1][3]=re[i][3];
			if(re[i][3]<n/2&&re[i+1][0]<re[i][0]+s[i+1].c)re[i+1][0]=re[i][0]+s[i+1].c,re[i+1][3]=re[i][3]+1,re[i+1][1]=re[i][1],re[i+1][2]=re[i][2];
		}
		cout<<re[n][0]<<endl;
		* */
	}
}
