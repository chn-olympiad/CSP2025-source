#include<bits/stdc++.h>
#define N int(1e5+5)
#define M int(1e5/2+5)
using namespace std;
struct node{
	int score,num;
};
int n;
node a[N][4];
int t;
node max1[N],max2[N],max3[N];
bool cmp(node a,node b){
	return a.score>b.score;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].score;
				a[i][j].num=j;
				if(j==1){
					max1[i]=a[i][j];
				}
				if(j==2){
					max2[i]=a[i][j];
				}
				if(j==3){
					max3[i]=a[i][j];
				}
			}
		}
		int lim=n/3;
		sort(max1+1,max1+1+n,cmp);
		sort(max2+1,max2+1+n,cmp);
		sort(max3+1,max3+1+n,cmp);
		int x=1,y=1,sum=0;
		int vis[N][4]={};
		for(int i=1;i<=n;i++){
			if(x==1){
				sum+=max1[y].score;
			}
			if(x==2){
				sum+=max2[y].score;
			}
			if(x==3){
				sum+=max3[y].score;
			}
			y++;
			if(y>=lim){
				y=1;
				x++;
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}
