#include<bits/stdc++.h>
using namespace std;

int max_3(int x,int y,int z){
	
	int m=max(x,y);
	    m=max(z,m);
	    return m;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;//总人数 
	int t;//数据组数
	cin>>t;
	cin>>n;
	
	for(int i=1;i<=t;i++){
		struct manyi{
			int a,b,c;
		}manyi[100010]; 
		
		int max1[100010];//每个人的满意度最大值 
		int flag[100010];//每个最大值属于哪个社团 1--a  2--b 3--c 
		int ans=0;//满意度之和
		int sum1=0,sum2=0,sum3=0;//每个club的人数  
		
	
		for(int j=1;j<=n;j++){
			cin>>manyi[j].a>>manyi[j].b>>manyi[j].c;
		}
		
		int temp=0;
		for(int j=1;j<=n;j++){
			if(manyi[j].b==manyi[j].c){
				temp=0;
			}else if(manyi[j].a==manyi[j].b){
				temp=0;
			}else if(manyi[j].a==manyi[j].c){
				temp=0;
			}else temp=1;
			
		}
		/*if(temp==0){//2 3全为0
		
			for(int j=1;j<=n;j++){
				a[j]=manyi[j].a;
			}
			sort(a+1,a+1+n);
			for(int j=n;j>(n/2);j--){
				ans=ans+a[j];
			}
			cout<<ans;
		
		} */
		
			for(int j=1;j<=n;j++){
			max1[j]=max_3(manyi[j].a,manyi[j].b,manyi[j].c);
			if(max1[j]==manyi[j].a){
				flag[j]=1;
			}else if(max1[j]==manyi[j].b){
				flag[j]=2;
			}else if(max1[j]==manyi[j].c){
				flag[j]=3;
			}
			if(flag[j]==1&&sum1<=(n/2)){
				sum1++;
				
			}
			if(flag[j]==2&&sum2<=(n/2)){
				sum2++;
			}
			if(flag[j]==3&&sum3<=(n/2)){
				sum3++;
			}
			
		} 
	if(temp==0){
		sort(max1+1,max1+1+n);
		for(int j=n;j>(n/2);j--){
			ans=ans+max1[j]; 
		}
		cout<<ans;
		break;
	} else for(int j=1;j<=n;j++){
		ans=ans+max1[j];
	}
	cout<<ans<<endl;
	
 	}
	
	return 0;
} 
