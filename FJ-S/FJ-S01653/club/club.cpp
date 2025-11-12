#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t;
struct student{
	int a,b,c;
};
student a[maxn];
int to[4];
//int dp[5000][5000];
int findmax(int i){
	
	int maxa=max(a[i].a,max(a[i].b,a[i].c));
	int maxc;
	if(a[i].a==maxa){
		maxc=1;
	}else if(a[i].b==maxa){
		maxc=2;
	}else if(a[i].c==maxa){
		maxc=3;
	}
	return maxc;
}
int themax(int i){
	return max(a[i].a,max(a[i].b,a[i].c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		memset(to,0,sizeof to);
		int n;
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			}
			int maxs=0;
			for(int i=1;i<=3;i++){
				if(i==1){
					maxs=max(maxs,a[2].a+a[1].b);
					maxs=max(maxs,a[2].a+a[1].c);
				}else if(i==2){
					maxs=max(maxs,a[2].b+a[1].a);
					maxs=max(maxs,a[2].b+a[1].c);
				}else if(i==3){
					maxs=max(maxs,a[2].c+a[1].a);
					maxs=max(maxs,a[2].c+a[1].b);
				}
			}
			printf("%d\n",maxs);
		}
		else if(n==4){
			int stu[maxn][4];
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&stu[i][1],&stu[i][2],&stu[i][3]);
			}
			int maxs=0;
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					for(int x=1;x<=4;x++){
						for(int y=1;y<=4;y++){
							if((i==j&&j==x)||(i==j&&j==y)||(i==x&&x==y)||(y==j&&j==x)) continue;
							maxs=max(maxs,stu[1][i]+stu[2][j]+stu[3][x]+stu[4][y]);
//							cout<<stu[1][i]<<stu[2][j]<<stu[3][x]<<stu[4][y]<<endl;
						}
					}
				}
			}
			cout<<maxs<<endl;
		}
		else{
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			to[findmax(i)]++;
		}
		if(to[1]<=(n>>1)&&to[2]<=(n>>1)&&to[3]<=(n>>1)){
			int ans=0;
			for(int i=1;i<=n;i++){
				int maxa=max(a[i].a,max(a[i].b,a[i].c));
				ans+=maxa;
			}
			cout<<ans<<endl;
		}else{//mafan
			memset(to,0,sizeof to);
			int ans=0;
			for(int i=1;i<=n;i++){
				int c=findmax(i);
				to[c]++;
				if(to[c]>(n>>1)){//大于n/2 
					
				}else{//小于n/2 
					ans+=themax(i);
				}
			}
		}
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
