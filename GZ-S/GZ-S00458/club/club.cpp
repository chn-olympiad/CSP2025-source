//CSP-S00458 贵阳1市第三实验中学 陈则睿 
#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	int a=0;
	char c=getchar();
	while('0'<=c&&c<='9'&&c!=' '&&c!='\n'){
		a=a*10+(c-'0');
		c=getchar();
	}
	x=a;
}
int a[1000010][3];
//法1
int choice[1000010][3],tot[3]; 

//法2 
//int choiceA[1000010],totA;
//int choiceB[1000010],totB;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;read(t);
	while(t--){
		int n;
		cin>>n;
//		for(int i=0;i<n;i++){cin>>a[i][0]>>a[i][1]>>a[i][2];}
//		for(int i=0;i<n;i++){read(a[i][0]);read(a[i][1]);read(a[i][2]);}
		for(int i=0;i<n;i++){
			int aa,b,c;
			scanf("%d%d%d",&aa,&b,&c);
			a[i][0]=aa,a[i][1]=b,a[i][2]=c;
		}
//		if(n<=200){
			tot[0]=0;tot[1]=0;tot[2]=0;
			for(int i=0;i<1000010;i++){
				choice[i][0]=0;choice[i][1]=0;choice[i][2]=0;
			}
			for(int i=0;i<n;i++){
				int fir,sec,thi;
				if(a[i][0]>=a[i][1]&&a[i][1]>=a[i][2])fir=0,sec=1,thi=2;//012
				if(a[i][0]>=a[i][2]&&a[i][2]>=a[i][1])fir=0,sec=2,thi=1;//021
				if(a[i][1]>=a[i][0]&&a[i][0]>=a[i][2])fir=1,sec=0,thi=2;//102
				if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][0])fir=1,sec=2,thi=0;//120
				if(a[i][2]>=a[i][0]&&a[i][0]>=a[i][1])fir=2,sec=0,thi=1;//201
				if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][0])fir=2,sec=1,thi=0;//210	
				if(tot[fir]<n/2){choice[tot[fir]++][fir]=i;}
				else{
					int min1=0;
					for(int j=0;j<tot[fir];j++){
						if(a[choice[j][fir]][sec]>a[choice[j][fir]][thi]){
							if(a[choice[min1][fir]][sec]>a[choice[min1][fir]][thi]){//s=sec
								if(a[choice[j][fir]][fir]-a[choice[j][fir]][sec]<a[choice[min1][fir]][fir]-a[choice[min1][fir]][sec]){
									min1=j;
								}
							}else{//s2=thi
								if(a[choice[j][fir]][fir]-a[choice[j][fir]][sec]<a[choice[min1][fir]][fir]-a[choice[min1][fir]][thi]){
									min1=j;
								}
							}
						}else{
							if(a[choice[min1][fir]][sec]>a[choice[min1][fir]][thi]){//s=sec
								if(a[choice[j][fir]][fir]-a[choice[j][fir]][thi]<a[choice[min1][fir]][fir]-a[choice[min1][fir]][sec]){
									min1=j;
								}
							}else{//s2=thi
								if(a[choice[j][fir]][fir]-a[choice[j][fir]][thi]<a[choice[min1][fir]][fir]-a[choice[min1][fir]][thi]){
									min1=j;
								}
							}
						}
//						if(min(a[choice[j][fir]][fir]-a[choice[j][fir]][sec],a[choice[j][fir]][fir]-a[choice[j][fir]][thi])<min(a[choice[min1][fir]][fir]-a[choice[min1][fir]][sec],a[choice[min1][fir]][fir]-a[choice[min1][fir]][thi])){
//							min1=j; 
//						}
					}
					if(min(a[choice[min1][fir]][fir]-a[choice[min1][fir]][sec],a[choice[min1][fir]][fir]-a[choice[min1][fir]][thi])<a[i][fir]-a[i][sec]){
						if(a[choice[min1][fir]][sec]<a[choice[min1][fir]][thi]){//thi是第二大的
							choice[tot[thi]++][thi]=choice[min1][fir];
							choice[min1][fir]=i;
						}else{
							choice[tot[sec]++][sec]=choice[min1][fir];
							choice[min1][fir]=i;
						}
					}else{
						choice[tot[sec]++][sec]=i;
					}
				}
			}
			int ans=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<tot[i];j++){
					ans+=a[choice[j][i]][i];
				}
			}
			cout<<ans<<'\n';
//		}
//		else{//super暴力的笑容，没有你的甜~ 
//			totA=0,totB=0;
//			for(int i=0;i<1000010;i++){
//				choiceA[i]=0;choiceB[i]=0;
//			}
//			for(int i=0;i<n;i++){
//				if(a[i][0]>=a[i][1]){
//					if(totA<(n/2)){choiceA[totA++]=i;}
//					else{
//						int min1=0;
//						for(int j=0;j<totA;j++){
//							if(a[choiceA[j]][0]-a[choiceA[j]][1]<a[choiceA[min1]][0]-a[choiceA[min1]][1]){min1=j;}
//						}
//						if(a[choiceA[min1]][0]-a[choiceA[min1]][1]<a[i][0]-a[i][1]){
//							choiceB[totB++]=choiceA[min1];
//							choiceA[min1]=i;
//						}else{
//							choiceB[totB++]=i;
//						}
//					}
//				}else{
//					if(totB<(n/2)){choiceB[totB++]=i;}
//					else{
//						int min1=0;
//						for(int j=0;j<totB;j++){
//							if(a[choiceB[j]][1]-a[choiceB[j]][0]<a[choiceB[min1]][1]-a[choiceB[min1]][0]){min1=j;}
//						}
//						if(a[choiceB[min1]][1]-a[choiceB[min1]][0]<a[i][1]-a[i][0]){
//							choiceA[totA++]=choiceB[min1];
//							choiceB[min1]=i;
//						}else{
//							choiceA[totA++]=i;
//						}
//					}	
//				}
//			}
//			int ans=0;
//			for(int i=0;i<totA;i++){
//				ans+=a[choiceA[i]][0];
////				cout<<choiceA[i]<<':'<<a[choiceA[i]][0]<<endl;
//			}
//			for(int i=0;i<totB;i++){
//				ans+=a[choiceB[i]][1];
////				cout<<choiceB[i]<<':'<<a[choiceB[i]][1]<<endl;
//			}
//			cout<<ans<<'\n';
//		}
	}
	return 0;
} 
