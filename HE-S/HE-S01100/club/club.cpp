#include<bits/stdc++.h>
using namespace std;
int t;
struct man{
	int l1,l2,l3;
	int wish;
	int chazhi;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int u=0;u<t;u++){
		long long sum[3]={0};
		long long ans=0;
		int key1=0;
		int n;cin>>n;
		man a[n];
		//前置
		 
		for(int j=0;j<n;j++){
			cin>>a[j].l1>>a[j].l2>>a[j].l3;
			if(a[j].l1>a[j].l2&&a[j].l1>a[j].l3){
				a[j].wish=1;
				ans+=a[j].l1;
				if(a[j].l2>a[j].l3){
					a[j].chazhi=a[j].l1-a[j].l2;
				}else{
					a[j].chazhi=a[j].l1-a[j].l3;
				}
				
			}
			if(a[j].l2>a[j].l3&&a[j].l2>a[j].l1){
			    a[j].wish=2;
				ans+=a[j].l2;	
				if(a[j].l3>a[j].l1){
					a[j].chazhi=a[j].l2-a[j].l3;
				}else{
					a[j].chazhi=a[j].l2-a[j].l1;
				}
				
			}
			if(a[j].l3>a[j].l1&&a[j].l3>a[j].l2){
				a[j].wish=3;
				ans+=a[j].l3;
				if(a[j].l2>a[j].l1){
					a[j].chazhi=a[j].l3-a[j].l2;
				}else{
					a[j].chazhi=a[j].l3-a[j].l1;
				} 
				
			} 
			sum[a[j].wish-1]++;
		}//求理想值，最大与其次差值 
		//第一坨大便山 
		
		int biggest;
		for(int i=0;i<3;i++){
			if(sum[i]>n/2){
				key1=1;
				biggest=i;
				break;
			} 
		} 
		//决定是否执行下一步操作 
		if(key1==0) cout<<ans<<endl;
		//理想值成立情况 
 		long long more[sum[biggest]]={0};long long sum1=0; 
		if(key1==1){
			//cout<<"-";
			//试图寻找bug1.0
			for(int i=0;i<n;i++){
				if(a[i].wish==biggest+1){
					more[sum1]=a[i].chazhi;
					//cout<<a[i].chazhi<<"-"; 
					//试图寻找bug2.0
					sum1++; 
					
				}
			}
			//寻找差值
			sort(more,more+sum1+1);
			//cout<<more[0]<<"-"<<more[1]<<"-";
			//试图寻找bug3.0
			int need=sum[biggest]-n/2;
			for(int i=0;i<need;i++){
				if(more[i]==0) need++;
				ans-=more[i];
			} 
			cout<<ans<<endl;
			//精悍结尾 
			//华丽收场 
		}
		//去掉多余糟粕 
	}
	//单for，时间复杂度最高 5*10^5
	
	//痛苦的敲了10分钟样例
	
	//凑两千字节                         
	return 0;
} 
