//GZ-S00459 贵阳市第一中学 陈加涵 
#include<bits/stdc++.h>
using namespace std;
int t;//数据组数
int n;
int a[100001][4];
bool flag1=0;//ai2=ai3=0
bool flag2=0;//ai3=0
bool cmp(int x,int y){
	return x>y;
}
void solve1(){
	int b[100001];
	for(int i=1;i<=n;i++){
		b[i]=a[i][1];
	}
	sort(b+1,b+1+n,cmp);
	long long sum=0;
	for(int i=1;i<=(n/2);i++){
		sum+=b[i];
	}
	cout<<sum<<endl;
	return;
}
void solve2(){
	long long sum=0;
	long long summax=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(j!=i){
				sum=0;
				sum+=a[1][i];
				sum+=a[2][j];
				summax=max(sum,summax);
			}
		}
	}
	cout<<summax<<endl;
	return;
}
void solve3(){
	int b[100001],c[100001];
	int sum=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i][1];
		c[i]=a[i][2];
	}
	sort(b+1,b+1+n,cmp);
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=(n/2);i++){
		sum+=b[i];
		sum+=c[i];
	}
	cout<<sum<<endl;
	return;
}
void solve4(){
	long long sum=0;
	long long summax=-1;
	int club[4]={0,0,0,0};
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				for(int h=1;h<=3;h++){
					sum=0;
					memset(club,0,sizeof(club));
					club[i]++;
					club[j]++;
					club[k]++;
					club[h]++;
					if(club[1]<=2&&club[2]<=2&&club[3]<=2){
						sum+=a[1][i];
						sum+=a[2][j];
						sum+=a[3][k];
						sum+=a[4][h];
						summax=max(sum,summax);
					}
				}
			}
		}
	}
	cout<<summax<<endl;
	return;
}
int solve5club[100001];
long long solve5sum=0;
long long solve5summax=-1;
void solve5(){
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		flag1=0;
		flag2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][2]!=0||a[i][3]!=0){
				flag1=1;
			}
			if(a[i][3]!=0){
				flag2=1;
			}
		}
		if(flag1==0){
			solve1();
		}
		else if(n==2){
			solve2();
		}
		else if(n==4){
			solve4();
		}
		else if(flag2==0){
			solve3();
		}
		else solve5();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
