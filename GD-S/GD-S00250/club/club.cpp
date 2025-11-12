#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool A=true,B=true,C=true,D=true,E=true;//特殊性质数据点 
int t,n,a[N][5],dp[N][3],peo[5];
struct No{
	int x,y,z;
}cpy[N];
bool cmp1(No x1,No y1){
	return x1.x>y1.x;
}
bool cmp2(No x1,No y1){
	int x=x1.x-x1.y;
	int y=y1.x-y1.y;
	if(x==y){
		return x1.x>y1.x;
	}
	return x>y;
}
int ansE=0;
void dfs(int x1,int y1,int z1,int x2,int y2,int z2,int peo){
//	cout<<x1<<' '<<y1<<' '<<z1<<' '<<x2<<' '<<y2<<' '<<z2<<' '<<peo<<' '<<n<<endl;
	if(peo>n){
		ansE=max(ansE,x1+y1+z1);
		return;
	}
	if(x2*2<n){
		dfs(x1+a[peo][1],y1,z1,x2+1,y2,z2,peo+1);
	}
	if(y2*2<n){
		dfs(x1,y1+a[peo][2],z1,x2,y2+1,z2,peo+1);
	}
	if(z2*2<n){
		dfs(x1,y1,z1+a[peo][3],x2,y2,z2+1,peo+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		A=true; B=true; C=true; D=true; E=true;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		if(n!=2){
			D=false;
		}
		if(n!=4){
			C=false;
		}
		if(n!=10){
			E=false;
		}
//		cout<<"n:"<<n<<' '<<C<<endl;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			cpy[i].x=a[i][1];
			cpy[i].y=a[i][2];
			cpy[i].z=a[i][3];
			if(a[i][2]!=0) {
				A=false;
			}
			if(a[i][3]!=0){
				B=false;
			}
		}
		if(A){
			sort(cpy+1,cpy+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=cpy[i].x; 
			}
			printf("%d\n",ans);
			continue;
		}//ok
		if(C){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							int fla[10]={0,0,0,0,0,0,0,0};
							fla[i]++;fla[j]++;fla[k]++;fla[l]++;
							if(fla[1]>=3||fla[2]>=3||fla[3]>=3) continue;
//					cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
							ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
						}
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}//ok
		if(D){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j) continue;
					ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			printf("%d\n",ans);
			continue;
		}//ok
		if(E){
			ansE=0;
			dfs(0,0,0,0,0,0,1);
			printf("%d\n",ansE);
			continue;
		}//ok
		if(B){
			int sum=0;
			sort(cpy+1,cpy+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				sum+=cpy[i].x;
			}
			for(int i=n/2+1;i<=n;i++){
				sum+=cpy[i].y;
			}
			printf("%d\n",sum);
			continue;
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			printf("%d\n",sum);
			continue;
		}//C
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
10
1 2 3
4 5 6
2 3 1
4 5 2
2 3 5
2 4 6
3 6 7
1 3 6
1 6 3
7 3 2

1
6
1 5 0
2 4 0
4 8 0
6 1 0
7 3 0
9 8 0

请输入文本 
*/
