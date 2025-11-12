//GZ-S00373 毕节七星关东辰实验学校  翟浩锡 
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[5][200005],b[200005];
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=3;i++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			int max_=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j)	continue;
					if(a[i][1]+a[j][2]>max_){
						max_=a[i][1]+a[j][2];
					}
				}
			}
			cout<<max_<<endl;
			continue;
		}
		if(n==100000){
			for(int j=1;j<=n;j++){
				if(a[2][j]==a[3][j] && a[2][j]==0){
					continue;
				}
				else{
					break;
				}
				int b[200005];
				for(int j=1;j<=n;j++){
					b[j]=a[1][j];
				}
				sort(b+1,b+n+1);
				for(int i=1;i<=n/2;i++){
					sum+=b[i];
				}
				cout<<sum<<endl;
				continue;
			}
		} 
	}
	return 0;
} 
