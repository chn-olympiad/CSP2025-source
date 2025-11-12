#include<bits/stdc++.h>
using namespace std;
struct R{
	int bm[5]={0,1,2,3,0};
	int my[5];
}; 
bool cnm(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int o=1;o<=t;o++){
		int n,a[100050][5],dp[100050]={},rs[5]={},mya[100050]={},myb[100050]={},myc[100050]={};
		cin>>n;
		int sx=n/2;
		for(int i=1;i<=n;i++){
			//dp[i]=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				
			}mya[i]=a[i][1];
			myb[i]=a[i][2];
			myc[i]=a[i][3];
			
		}//dp[1]=
		sort(mya+1,mya+1+n,cnm);
		sort(myb+1,myb+1+n,cnm);
		sort(myc+1,myc+1+n,cnm);
		//the first dp
		for(int i=1;i<=n;i++){
			int _1=0,_2=0,_3=0;
			//int _a=0,_b=0,_c=0;
			//int a=0,b=0,c=0
			if(rs[1]<=sx){
				_1=a[i][1];
			}if(rs[2]<=sx){
				_2=a[i][2];
			}if(rs[3]<=sx){
				_3=a[i][3];
			}
			if(max(_1,max(_2,_3))==_1){
				rs[1]++;
				if(rs[1]>sx){
					_1=0;
				}
				//cout<<rs[1];
			}else if(max(_1,max(_2,_3))==_2){
				rs[2]++;
				if(rs[2]>sx){
					_2=0;
				}
			}else if(max(_1,max(_2,_3))==_3){
				rs[3]++;
				if(rs[3]>sx){
					_3=0;
				}
			}
			dp[i]=max(dp[i-1]+_1+dp[i],max(dp[i-1]+_2+dp[i],dp[i-1]+_3+dp[i]));
		}cout<<dp[n]<<"\n";
	}
	return 0;
}
