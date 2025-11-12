#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100010][3],vis[100010][3],ans=0;
int find(int x){//函数查找满意度最大的部门
	int m=max(a[x][1],max(a[x][2],a[x][3]));
	for(int i=1;i<=3;i++){
		if(a[x][i]==m){
			return i;
		}
	}
}
void solve1(){
	int sum=0,f1=0,f2=0,f3=0;//分别计算三个部门人数 
	for(int i=1;i<=n;i++) vis[i][find(i)]=1;//首先把员工放入满意度最大的部门
    for(int i=1;i<=n;i++){
    	if(vis[i][1]==1){
    		f1++;
    		sum+=a[i][1];
		}
		if(vis[i][2]==1){
    		f2++;
    		sum+=a[i][2];
		}
		if(vis[i][3]==1){
    		f3++;
    		sum+=a[i][3];
		}
	}
	if(f1<=n/2&&f2<=n/2&&f3<=n/2){//三个部门人数都不超过则输出 
		cout<<sum<<endl;
	}
}
void dfs(int x,int c1,int c2,int c3,int sum){
	if(c1>n/2||c2>n/2||c3>n/2) return;
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,c1+1,c2,c3,sum+a[x][1]);
	dfs(x+1,c1,c2+1,c3,sum+a[x][2]);
	dfs(x+1,c1,c2,c3+1,sum+a[x][3]);
}
void solve2(){
	ans=0;
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);//存满意度 
        if(n<=10) solve2();//n<=10,dfs暴力 3^10次
		else{
		    int mb=0,ma=0,mc=0,sum=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]==0) ma++;
				if(a[i][2]==0) mb++;
				if(a[i][3]==0) mc++;
			}	
			if(mb==n&&mc==n){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(a[i][1]<a[j][1]) swap(a[i][1],a[j][1]);
					}
				}
				for(int i=1;i<=n/2;i++) sum+=a[i][1];
				cout<<sum;
				return 0;
			} 
		} 
	    solve1();
	}
    

	return 0;
}
//共三个部门,n个成员,算出最大满意度,每个部门不超过n/2人
//怎么放,可以建一个100000*3的数组先存下满意度, 
//如果每个部门人数没超,输出
//否则将部分员工调离到其他部门,要求满意度减小得最少 
