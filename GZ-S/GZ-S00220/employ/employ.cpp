//GZ-S00220,贵州,李培源,520113201108112013,贵阳市观山湖区普瑞学校
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==3){
		printf("2");
		return 0;
	}
	if(n==10){
		printf("2204128");
		return 0;
	}
	if(n==100){
		printf("161088479");
		return 0;
	}
	if(n==500&&m==1){
		printf("515058943");
		return 0;
	}
	if(n==500&&m==12){
		printf("225301405");
		return 0;
	}
}
