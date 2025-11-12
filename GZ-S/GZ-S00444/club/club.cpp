//GZ-S00444 郭一鸣 贵阳雅礼高级中学 
#include<bits/stdc++.h>
using namespace std;
long int a[100000][4];
long int Max(long int n){
	long int s[n][5];
	for(int i=0;i<n;i++){
		int fir=0,last=1000;
		for(int j=0;j<3;j++){
			if(a[i][j]>fir) {
				fir=a[i][j];
				s[i][0]=j+1;
			}
			if(a[i][j]<last){
				last=a[i][j];
				s[i][2]=j+1;
			}
		}
		s[i][1]=6-s[i][0]-s[i][2];
	}
	//得出每个新生最想去的，第二想去的和最不想去的部门(已验证) 
	int xiangyi=0,xianger=0,xiangsan=0;
	for(int i=0;i<n;i++){
		if(s[i][0]==1) {
			xiangyi++;
		}
		else if(s[i][0]==2) {
			xianger++;
		}
		else if(s[i][0]==3) {
			xiangsan++;
		}
	} 
	//统计最想去各部门的新生人数(已验证)
	for(int i=0;i<n;i++){
		long int x=s[i][0],y=s[i][1];
		s[i][3]=a[i][x-1]-a[i][y-1];
	}
	//统计每个新生 最想去部门的评分与中立部门的评分之差(s[i][3])(已验证)
	long int Maxzhongpingfen=0;
	if(xiangyi<=n/2&&xianger<=n/2&&xiangsan<=n/2){
		for(int i=0;i<n;i++){
			long int x=s[i][0];
			Maxzhongpingfen+=a[i][x-1];
		}
		return Maxzhongpingfen;
	}
	//没有超出小L的分派方案要求 (已验证) 
	else {
		if(xiangyi>n/2) {
			long int w[n];
			for(int i=0;i<n;i++){
				if(s[i][0]==2) Maxzhongpingfen+=a[i][2];
				else if(s[i][0]==3) Maxzhongpingfen+=a[i][3];
			}
			long int chamin=1000,min;
			for(int i=0;i<n;i++){
				w[i]=i;
			}
			for(int j=0;j<xiangyi-n/2;j++){
				int i;
				for(i=0;i<n;i++){
					if(s[i][3]<chamin) {
						chamin=s[i][3];
						min=i;	
					}
				}
				s[min][3]=1000;
				chamin=1000;
				Maxzhongpingfen+=a[min][s[min][1]-1];
				w[min]=100000;
			}
			for(int i=0;i<n;i++){
				if(w[i]!=100000) {
					Maxzhongpingfen+=a[i][s[i][0]-1];
				}
			}
			return Maxzhongpingfen;
		}
		else if(xianger>n/2) {
			long int w[n];
			for(int i=0;i<n;i++){
				if(s[i][0]==1) Maxzhongpingfen+=a[i][1];
				else if(s[i][0]==3) Maxzhongpingfen+=a[i][3];
			}
			long int chamin=1000,min;
			for(int i=0;i<n;i++){
				w[i]=i;
			}
			for(int j=0;j<xianger-n/2;j++){
				long int i;
				for(i=0;i<n;i++){
					if(s[i][3]<chamin) {
						chamin=s[i][3];
						min=i;	
					}
				}
				s[min][3]=1000;
				chamin=1000;
				Maxzhongpingfen+=a[min][s[min][1]-1];
				w[min]=100000;
			}
			for(int i=0;i<n;i++){
				if(w[i]!=100000) {
					Maxzhongpingfen+=a[i][s[i][0]-1];
				}	
			}
			return Maxzhongpingfen;
		}
		if(xiangsan>n/2) {
			long int w[n];
			for(int i=0;i<n;i++){
				if(s[i][0]==1) Maxzhongpingfen+=a[i][1];
				else if(s[i][0]==2) Maxzhongpingfen+=a[i][2];
			}
			long int chamin=1000,min;
			for(int i=0;i<n;i++){
				w[i]=i;
			}
			for(int j=0;j<xiangsan-n/2;j++){
				long int i;
				for(i=0;i<n;i++){
					if(s[i][3]<chamin) {
						chamin=s[i][3];
						min=i;	
					}
				}
				s[min][3]=1000;
				chamin=1000;
				Maxzhongpingfen+=a[min][s[min][1]-1];
				w[min]=100000;
			}
			for(int i=0;i<n;i++){
				if(w[i]!=100000) {
					Maxzhongpingfen+=a[i][s[i][0]-1];
				}
				
			}
			return Maxzhongpingfen;
		}
	}
	//超出小L的分配方案要求 一超/二超/三超 
}
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	long int t,n,ans[1000];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
			}
		}
		ans[i]=Max(n);
	}
	for(int j=0;j<t;j++){
		cout<<ans[j]<<endl;
	}
}
