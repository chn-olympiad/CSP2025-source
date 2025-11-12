#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=100001;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[MAXN][4],ma,mb,mc;
	long long max[6]={0};
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&a[j][1],&a[j][2],&a[j][3]);
		}
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				if(k!=j){
					if(a[1][j]+a[2][k]>max[i]){
						max[i]=a[1][j]+a[2][k];
					}
				}
			}
		}
	}
	for(int i=1;i<=t-1;i++){
		cout<<max[i]<<endl;
	}
	cout<<max[t];
	return 0;
}
