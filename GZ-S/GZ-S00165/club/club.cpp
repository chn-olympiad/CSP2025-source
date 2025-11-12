//ÕÅÐÀÒã  GZ-S00165  ËçÑôÏØËçÑôÖÐÑ§ 
#include<iostream>
#include<stdio.h>
using namespace std;

long p[2000000];
int num=1;int n,t;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
	cin>>n;int num1=0,num2=0,num3=0;int pe[30010][3]={0,0,0};int ans1=0,ans2=0,ans3=0;
	for(int i=1;i<=n;i++){
		cin>>pe[i][1]>>pe[i][2]>>pe[i][3];
	}
	for(int f=1;f<=n;f++){
		 if(pe[f][1]>pe[f][2]&&pe[f][1]>pe[f][3]&&num1<=n/2){
			++num1;ans1+=pe[f][1];
			if(num1==n/2&&(ans1-pe[f][1])>=(ans2-pe[f][2])&&(ans1-pe[f][1])>=(ans3-pe[f][3])){
			}else if(num1==n/2&&(ans1-pe[f][1])<=(ans2-pe[f][2])&&(ans2-pe[f][2])>=(ans3-pe[f][3])&&pe[f][2]>=pe[f][3]){
				ans1-=pe[f][1];ans2+=pe[f][2];--num1,++num2;
			}else if(num1==n/2&&(ans1-pe[f][1])<=(ans3-pe[f][3])&&(ans3-pe[f][3])>=(ans2-pe[f][2])&&pe[f][3]>=pe[f][2]){
				ans1-=pe[f][1];ans3+=pe[f][3];--num1,++num3;
			}
		}else if(pe[f][1]<pe[f][2]&&pe[f][2]>pe[f][3]&&num2<=n/2){
		        ++num2;ans2+=pe[f][2];
			if(num2==n/2&&(ans2-pe[f][2])>=(ans1-pe[f][1])&&(ans2-pe[f][2])>=(ans3-pe[f][3])){
			}else if(num2==n/2&&(ans2-pe[f][2])<=(ans1-pe[f][1])&&(ans1-pe[f][1])>=(ans3-pe[f][3])&&pe[f][1]>=pe[f][3]){
				ans2-=pe[f][2];ans1+=pe[f][1];--num2,++num1;
			}else if(num2==n/2&&(ans2-pe[f][2])<=(ans3-pe[f][3])&&(ans3-pe[f][3])>=(ans1-pe[f][1])&&pe[f][3]>=pe[f][1]){
				ans2-=pe[f][2];ans3+=pe[f][3];--num2,++num3;
			}
		}else if(num3<=n/2){
		++num3;ans3+=pe[f][3];
				if(num3==n/2&&(ans3-pe[f][3])>=(ans2-pe[f][2])&&(ans3-pe[f][3])>=(ans1-pe[f][1])){
			}else if(num3==n/2&&(ans3-pe[f][3])<=(ans1-pe[f][1])&&(ans1-pe[f][1])>=(ans2-pe[f][2])&&pe[f][1]>=pe[f][2]){
				ans3-=pe[f][3];ans1+=pe[f][1];--num3,++num1;
			}else if(num3==n/2&&(ans3-pe[f][3])<=(ans2-pe[f][2])&&(ans2-pe[f][2])>=(ans1-pe[f][1])&&pe[f][2]>=pe[f][1]){
				ans3-=pe[f][3];ans2+=pe[f][2];--num3,++num2;
			}	
		}
	}
	p[j]=ans1+ans2+ans3;
	}
	for(int k=1;k<=t;k++)cout<<p[k]<<"\n";;
	return 0;
}



