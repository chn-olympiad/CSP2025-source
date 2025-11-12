//GZ-S00079 贵阳市第三实验中学 向信昌 
#include<bits/stdc++.h>
using namespace std;
int t=0,n=0,ans=0,max_1=-1,max_2=-1,max_3=-1,a1=0,a2=0;
int myd[200001][4];
int b1[4];
int fl[4];
int main(){
	//开头这一块 
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	//小测试点开始 
	for(int k=1;k<=t;k++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){ //录入数据 
			cin>>myd[i][1];
			cin>>myd[i][2];
			cin>>myd[i][3];
		}
		for(int i=1;i<=4;i++) b1[i]=0;
		for(int i=1;i<=n;i++){
			for(int p=1;p<=4;p++) fl[p]=0;
			a1=0;a2=0;
			max_1=-1;
			max_2=-1;
			max_3=-1;
			for(int j=1;j<=3;j++){
				if(myd[i][j]>max_1){
					max_1=myd[i][j];
					a1=j;
					fl[j]=1;
				}
			}
			for(int j=1;j<=3;j++){
				if(myd[i][j]>max_2 and myd[i][j]<=max_1 and fl[j]!=1){
					max_2=myd[i][j];
					a2=j;
					fl[j]=1;
				}
			}
			for(int j=1;j<=3;j++){
				if(myd[i][j]>max_3 and myd[i][j]<=max_1 and myd[i][j]<=max_2 and fl[j]!=1){
					max_3=myd[i][j];
				}
			}
			//判断是否该对ans增加 
			if(b1[a1]<=(n/2)){
				ans+=max_1;
				b1[a1]+=1;
			}
			else if(b1[a2]<=(n/2)){
				ans+=max_2;
				b1[a2]+=1;
			}
			else{
				ans+=max_3;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
