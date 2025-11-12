#include<bits/stdc++.h>
using namespace std;
int renshus[100005][5];
int bianhao[100005][5];
int bumen[5];
int zong[100005];
int bumen_num[5];
int n,he;
int shuchu[100005]; 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	
	for(int l=1;l<=t;l++){
		he=0;
		
		for(int i=1;i<=3;i++){
		bumen[i]=0;
		bumen_num[i]=0;
	}
	
		cin>>n;
		
		//编号 
		for(int i=1;i<=n;i++){
			zong[i]=0;
			for(int j=1;j<=3;j++){
				bianhao[i][j]=j;
			}
		}
		
		//输入 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>renshus[i][j];
			}
		}
		
		//总数 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				zong[i]+=renshus[i][j];
			}
		}
		
		
		//比较替换大前
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(zong[i]<zong[j]){
					swap(zong[i],zong[j]);
					swap(renshus[i][1],renshus[j][1]);
					swap(renshus[i][2],renshus[j][2]);
					swap(renshus[i][3],renshus[j][3]);
				}
			}
		} 
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2;j++){
				for(int k=j+1;k<=3;k++){
					if(renshus[i][j]<renshus[i][k]){
						swap(renshus[i][j],renshus[i][k]);
						swap(bianhao[i][j],bianhao[i][k]);
					}
				}
			}
	}




//添加
			for(int i=1;i<=n;i++) {
				if(n/2>bumen_num[bianhao[i][1]]){
					bumen[1]+=renshus[i][1];
					bumen_num[bianhao[i][1]]+=1;	
				} else if(n/2>bumen_num[bianhao[i][2]]){
					bumen[2]+=renshus[i][2];
					bumen_num[bianhao[i][2]]+=1;
				} else if(n/2>bumen_num[bianhao[i][3]]){
					bumen[3]+=renshus[i][3];
					bumen_num[bianhao[i][3]]+=1;
				}
			}
			
		//cout<<bumen_num[1]<<endl;
		//cout<<bumen_num[2]<<endl;
		//cout<<bumen_num[3]<<endl;
		
		
		//特例判断
		
		if(n==2){
			cout<<renshus[1][2]+renshus[2][1]<<" ";
			if(renshus[1][2]+renshus[2][1]>bumen[1]){
				bumen[1]=renshus[1][2]+renshus[2][1];
			}
		}
		
		 
		//输出 
		for(int i=1;i<=3;i++){
			//cout<<bumen[i]<<" ";
			
			he+=bumen[i];
		}
		shuchu[l]=he;
		//shuchu[1]=he;
	}
	for(int i=1;i<=t;i++){
		cout<<shuchu[i]<<" ";
	}

	return 0;
	
}
		
	
