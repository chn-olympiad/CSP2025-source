#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int n;
int tot1,tot2,tot3;//wei zhi
int sum1,sum2,sum3;//ren shu
struct node{
	int zhi,id,to;
}bum1[100005],bum2[100005],bum3[100005];
long long a[100005][4];
bool vis[100005][4];
long long sum;
bool cmp(node x,node y){
	return x.zhi>y.zhi;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club4.in","r",stdin);
//	freopen("club4.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		sum1=sum2=sum3=0;
		sum=0;
		tot1=tot2=tot3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			vis[i][1]=vis[i][2]=vis[i][3]=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				sum1++;
				bum1[++tot1]=(node){a[i][1]-a[i][2],i,2};
				bum1[++tot1]=(node){a[i][1]-a[i][3],i,3};
				vis[i][1]=1;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				sum2++;
				bum2[++tot2]=(node){a[i][2]-a[i][3],i,3};
				bum2[++tot2]=(node){a[i][2]-a[i][1],i,1};
				vis[i][2]=1;
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				sum3++;
				bum3[++tot3]=(node){a[i][3]-a[i][1],i,1};
				bum3[++tot3]=(node){a[i][3]-a[i][2],i,2};
				vis[i][3]=1;
			} 
		}
		if(sum1>(n/2)){
			sort(bum1+1,bum1+tot1+1,cmp);
			while(sum1>(n/2)){
				int i=bum1[tot1].id;
				int towho=bum1[tot1].to;
				if(vis[i][1]){
					vis[i][1]=0,sum1--;
					if(towho==2){
						vis[i][2]=1;
					}
					if(towho==3){
						vis[i][3]=1;
					}
				}else{
					;
				}
				tot1--;
			}
		}
		if(sum2>(n/2)){
			sort(bum2+1,bum2+tot2+1,cmp);
			while(sum2>(n/2)){
				int i=bum2[tot2].id;
				int towho=bum2[tot2].to;
				if(vis[i][2]){
					vis[i][2]=0,sum2--;
					if(towho==1){
						vis[i][1]=1;
					}
					if(towho==3){
						vis[i][3]=1;
					}
				}else{
					;
				}
				tot2--;
			}
		}
		if(sum3>(n/2)){
			sort(bum3+1,bum3+tot3+1,cmp);
			while(sum3>(n/2)){
				int i=bum3[tot3].id;
				int towho=bum3[tot3].to;
				if(vis[i][3]){
					vis[i][3]=0,sum3--;
					if(towho==1){
						vis[i][1]=1;
					}
					if(towho==2){
						vis[i][2]=1;
					}
				}else{
					;
				}
				tot3--;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i][1])sum+=a[i][1];
			if(vis[i][2])sum+=a[i][2];
			if(vis[i][3])sum+=a[i][3];
		}
		cout<<sum<<"\n";
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
*/
