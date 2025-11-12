#include<bits/stdc++.h>
using namespace std;
int a[100005][4];//a[i][j]表示第i个成员对第j个社团的满意程度
int t,n;//t表示数据组数,n表示新成员个数 
bool vis_tmp[4][100005];//访问数组 
int vis[4][100005];
//动态规划 
//long long dp[100005][4];
//int dp1[100005][4];
//声明数组,存储
const int mm=100005/2;
int numm[4][mm] ;
int maxa=-1,num=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);//输入t 
	//有含有0的数据似乎无法处理，可以直接偷分解决? 
	//ai2==ai3==0,意味着只需要判断ai1 
	while(t--){
		scanf("%d",&n);//输入n
		int tmp=n/2;
		//输入a数组
		for(int i=1;i<=n;i++){
			//输入第i个成员对第1~3个社团的满意程度
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]); 
		} 
		//特殊情况
		bool flag=true,flag1=true;
		for(int i=1;i<=n;i++){
			//有ai2=ai3=0 
			if(a[i][3]!=0){
				flag1=flag=false;
			}
			if(a[i][2]!=0){
				flag=false;
			}
		} 
		if(flag){
			//a[i][2],a[i][3]都是0 
			//判断a[i][1]
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					//如果前一个小
					if(a[i][1]<a[j][1]) swap(a[i][1],a[j][1]);
				}
			} 
			long long anssss=0;
			//输出前tmp位的和
			for(int i=1;i<=tmp;i++){
				anssss+=a[i][1];
			} 
			printf("%lld",anssss);
			continue;
		}
		if(flag1){
			//判断ai1,ai2
			//都放在1,2
			//每个人放每个人的最高
			long long ansans=max(a[1][1],a[1][2]);
			if(ansans==a[1][1]) {vis[1][1]=1;vis[2][1]=0;}
			else{vis[2][1]=1;vis[1][1]=0;}
			int maxa1=-1,maxa2=-1;
			int anss=0;
			for(int j=2;j<=n;j++){
				maxa1=max(maxa1,a[j][1]),maxa2=max(maxa2,a[j][2]);
			}
			bool hd1=false,hd2=false;//标志 
			//找
			for(int j=2;j<=n;j++){
				if(maxa1==a[j][1]&&maxa2==a[j][2]){
					//加上大的
					if(vis[2][1]==1){
						if(maxa2>=maxa1){
							//之后直接找ai1 
							ansans+=maxa2;
							hd2=true;
							break;
						}
						else{
							ansans+=maxa1;
							break;
						}
					} 
					else{
						if(maxa2<=maxa1){
							//之后直接找ai2 
							ansans+=maxa1;
							hd1=true;
							break;
						}
						else{
							ansans+=maxa2;
							break;
						}
					} 
				}
			} 
			int a1[n+1],a2[n+1];
			for(int i=1;i<=n;i++){
				a1[i]==a[i][1];
			}
			sort(a1+1,a1+n+1);
			for(int i=1;i<=n;i++){
				a2[i]==a[i][2];
			}
			sort(a2+1,a2+n+1);
			if(hd1){
				//排序ai2
				//怎么排
				//数组存储 
				ansans+=(a1[n-2]+a1[n-3]);
				printf("%lld\n",ansans);
			}
			else if(hd2){
				
				ansans+=(a2[n-2]+a2[n-3]);
				printf("%lld\n",ansans);
			}
			else{
				//需比对两个最大值之前是否为同一组
				//怎么比对
				int aa=maxa1,bb=maxa2;
				maxa1=maxa2=-1;
				for(int i=1;i<=n;i++){
					if(maxa1<a[i][1]&&a[i][1]!=aa){
						maxa1=a[i][1];
					}
					if(maxa2<a[i][2]&&a[i][2]!=bb){
						maxa2=a[i][2];
					}
				} 
				int flag_=0,flag11=-1;//标记 
				//从后往前找
				for(int i=1;i<=n;i++){
					if(maxa1==a[i][1]&&maxa2==a[i][2]){
						flag_=1;
						if(maxa1>=maxa2){
							flag11=1;
						}
						else flag11=2;
						break;
					}
				} 
				if(flag_){
					if(flag11==1){
						ansans+=(a1[n-1]+a2[n-2]);
					}
					else ansans+=(a1[n-2]+a2[n-1]);
				}
				else ansans+=(a1[n-1]+a2[n-1]);
				printf("%lld\n",ansans);
			}
			continue;
		}
		//开始计算满意度
		//背包问题
		long long yu=0;
		for(int j=1;j<=3;j++){
			num=0;
//			printf("j=%d\n",j);
			maxa=a[1][j];
			for(int i=1;i<=n;i++){
				if(a[i][j]>maxa){
					num=1;
					maxa=a[i][j];//重新赋值 
					continue;
				} 
				if(a[i][j]==maxa){
					num++;
				}
			}
			//判断num
			if(num>tmp){
				num=tmp;
				int ans=0;//计算找了几个 
				//找到前tmp个 
				for(int p=1;p<=n;p++){
					//够了
					if(ans==tmp) break;
					//如果没被用过 
					if(vis_tmp[1][p]==0&&vis_tmp[2][p]==0&&vis_tmp[3][p]==0&&a[p][j]==maxa){
						//用
//						printf("第%d个成员去到了第%d个社团!\n",p,j);
						vis_tmp[j][p]=1;
						ans++;
						yu+=a[p][j];
					}
				}
			}
			//如果num值正确 
			else{
				int ans=0;//计算找了几个 
				//找到num个 
				for(int p=1;p<=n;p++){
					//够了
					if(ans==num) break;
					//如果没被用过 
					if(vis_tmp[1][p]==0&&vis_tmp[2][p]==0&&vis_tmp[3][p]==0&&a[p][j]==maxa){
						//用
//						printf("第%d个成员去到了第%d个社团!\n",p,j);
						vis_tmp[j][p]=1;
						ans++;
						yu+=a[p][j];
					}
				}
				//再找次大的补足
				int min_cha=20000;
				for(int p=1;p<=n;p++){
					if(a[p][j]==maxa){
						//跳过
						continue; 
					}
					int tmp1=maxa-a[p][j];
					min_cha=min(min_cha,tmp1);//更新差值 
				} 
				//找出来
				int tmp2=tmp-num;
//				printf("num==%d,tmp2==%d\n",num,tmp2);
				int aaa=maxa-min_cha;
//				printf("aaa=%d\n",aaa);
				//多少
				int ans2=0; 
				for(int p=1;p<=n;p++){
					//够了
					if(ans2==tmp2) break;
					//如果没被用过 
					if(vis_tmp[1][p]==0&&vis_tmp[2][p]==0&&vis_tmp[3][p]==0&&a[p][j]==aaa){
						//用
//						printf("第%d个成员去到了第%d个社团!\n",p,j);
						vis_tmp[j][p]=1;
						ans2++;
						yu+=a[p][j];
					}
				}
			}
		} 
		printf("%lld\n",yu) ;
	}
	return 0;
}
