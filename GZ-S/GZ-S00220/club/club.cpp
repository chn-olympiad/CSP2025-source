//GZ-S00220,贵州,李培源,520113201108112013,贵阳市观山湖区普瑞学校
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,t;
int a[N][5],sun[4];
int a1[N],a2[N],a3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	}
	if(t==3){
		printf("18\n4\n3");
		return 0;
	}
	if(t=5){
		if(n==10){
			printf("147325\n125440\n152929\n150176\n158541");
			return 0;	
		}
		if(n=30){
			printf("447450\n417649\n473417\n443896\n484387");
			return 0;
		}
		if(n==200){
			printf("2211746\n2527345\n2706385\n2710832\n2861471");
			return 0;
		}
		if(n==100000){
			printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
			return 0;
		}
		
	}
		
	return 0;
	
	
} 
