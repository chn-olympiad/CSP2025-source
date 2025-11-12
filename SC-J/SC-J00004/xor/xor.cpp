#include<bits/stdc++.h>
using namespace std;
int yi(int x,int y){
	int poww=32768,ans=0;
	while(x!=0||y!=0){
		bool lun=0;
		if(x-poww>=0){
			lun=!lun;
			x-=poww;
		}
		if(y-poww>=0){
			lun=!lun;
			y-=poww;
		}
		if(lun) ans+=poww;
		poww=poww/2;
	}
	return ans;
}
int a[1000]={};
int num[3000][300]={};
int main(){
	int n,k;
	cin>>n>>k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<=3000) num[a[i]][i]++;
		for(int j=0;j<=2900;j++){
			if(i==0) break;
			if(num[j][i-1]!=0){
				if(yi(a[i],j)<=3000){
					num[yi(i,j)][i]+=num[j][i-1];
				} 
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=3;j++){
			cout<<num[j][i]<<" ";
		}
		cout<<endl;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=num[k][i];
	}
	cout<<ans;
}