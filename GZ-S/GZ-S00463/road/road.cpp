//GZ-S00463 六盘水市第四实验中学 陈子轩 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0,sum1=0,a[1000000][5],c[10000][10000],p=1,m1=10000,m2=10000,m3=10000;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0) p=0;
		}
	}
	if(p==1||n==1){
		cout<<0;
		return 0;
	}
	if(k==0){
		for(int i=0;i<m;i++){
			if(a[i][3]<m1){
				m3=m2;
				m2=m1;
				m1=a[i][3];
			}
			else if(a[i][3]<m2){
				m3=m2;
				m2=a[i][3];
			}
			else if(a[i][3]<m3){
				m3=a[i][3];
			}
		}
		cout<<m1+m2+m3;
		return 0;
	}
	for(int i=0;i<n;i++){
		sum+=c[0][i];
		sum1+=a[i][2];
	}
	cout<<min(sum,sum1);
	return 0;
}
