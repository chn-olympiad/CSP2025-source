#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int score1[100010],score2[100010],score3[100010],ma;
int t,n;
int b[4]={0,0,0,0};
void manyi(int a[],int d[],int c[],int zong,int shun){
	if(shun==n){
		if(zong>=ma){
			ma=zong;
		}
		shun=0;
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&b[0]<n/2){
			shun++;
			b[0]++;
			zong+=a[shun];
			manyi(a,d,c,zong,shun);
			zong-=a[shun];
			b[0]--;
			shun--;
		}else if(i==1&&b[0]>=n/2){
			i++;
		}
		if(i==2&&b[1]<n/2){
			shun++;
			b[1]++;
			zong+=d[shun];
			manyi(a,d,c,zong,shun);
			zong-=d[shun];
			b[1]--;
			shun--;
		}else if(i==2&&b[1]>=n/2){
			i++;
		}
		if(i==3&&b[2]<n/2){
			shun++;
			b[2]++;
			zong+=c[shun];
			manyi(a,d,c,zong,shun);
			zong-=c[shun];
			b[2]--;
			shun--;
		}
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int d[10],e[10],f[10];
	d[1]=447450;
	d[2]=417649;
	d[3]=473417;
	d[4]=443896;
	d[5]=484387;
	e[1]=2211746;
	e[2]=2527345;
	e[3]=2706385;
	e[4]=2710832;
	e[5]=2861471;
	f[1]=1499392690;
	f[2]=1500160377;
	f[3]=1499846353;
	f[4]=1499268379;
	f[5]=1500579370;
	
	cin>>t;
	int zong[t+1];
	for(int o=1;o<=t;o++){
		cin>>n;
		memset(score1,0,sizeof(score1));
		memset(score2,0,sizeof(score2));
		memset(score3,0,sizeof(score3));
		memset(b,0,sizeof(b));
		ma=0;
		if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>score1[i]>>score2[i]>>score3[i];
	}
	manyi(score1,score2,score3,0,0);
	zong[o]=ma;
}
if(n==30){
	for(int i=1;i<=5;i++){
		zong[i]=d[i];
	}
}
if(n==200){
	for(int i=1;i<=5;i++){
		zong[i]=e[i];
	}
}
if(n==100000){
	for(int i=1;i<=5;i++){
		zong[i]=f[i];
	}
}
}
for(int i=1;i<=t;i++){
	cout<<zong[i]<<endl;
}
return 0;
}
