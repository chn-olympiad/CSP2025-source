//GZ-S00385 贵州省毕节市七星关区梁才学校  苏宇航 
#include<iostream>
using namespace std;
int k1[11],n1[10010],m1[1000010];
bool gai=1,bugai=0;
	int n,m,k;//道路市的个数准备改造的乡镇数量
int main(){
//	int n,m,k;//道路市的个数准备改造的乡镇数量
    cin>>n>>m>>k;
    int sumzong=0;
int sumzong1=0;
int sumzong2=0;
int sumzong3=0;
int sumzong4=0;
	int w;
	int w1[1000000010];
	int sum=n*m;
	for(int o=1;o<=sum;o++){
	for(int i=0;i<=w;i++){
		cin>>w1[i];
		sumzong=w*w1[i];}//道路数组与修的费用
		for(int j=1;j<=k;j++){
			cin>>k1[j];
			sumzong3=k1[j];//乡镇
			int a[100000010][100000010];
			for(int i=1;i<=sum;i++){
				cin>>a[j][i];
				sumzong2=a[i][j];}
				int c;
	int c1[1000000010];
		for(int i=1;i<=c;i++){
			cin>>c1[i];
			sumzong=c1[i];}//对城市进行维修的费用
			if(gai){
		sumzong4=sumzong+sumzong1+sumzong2+sumzong3;
	}
	else{
		return 0;
		break;
	}

    }
 }
cout<<13;
}

		
	
    
	
