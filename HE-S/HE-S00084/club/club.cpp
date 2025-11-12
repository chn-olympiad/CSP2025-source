#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;	cin>>t;
	int sum[t+1];
	for(int l=1;l<=t;++l){
		int n;	cin>>n;
		int a[n+2][4],memo[n+2][4];
		bool b[n+2];
		for(int i=1;i<=n;++i){//每一组数据 
			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			memo[i][1]=a[i][1];	memo[i][2]=a[i][2];	memo[i][3]=a[i][3];
			b[i]=false;
		}
		
		int res1=0;
		for(int i=1;i<=n;++i){
			if(a[i][1]>a[i-1][1]){
				swap(a[i][1],a[i-1][1]);
			}
		}
		for(int k=1;k<=n/2;++k){
			res1+=a[k][1];
			b[k]=true;
		}
			
		int res2=0;
//		a[i][1]=memo[i][1];	a[i][2]=memo[i][2];	a[i][3]=memo[i][3];
		for(int i=1;i<=n;++i){
			if((a[i][2]>a[i-1][2])&&(b[i]==false)){
				swap(a[i][2],a[i-1][2]);
			}
		}
		for(int k=1;k<=n/2;++k){
			res2+=a[k][2];
			b[k]=true;
		}
			
		int res3=0;
//		a[i][1]=memo[i][1];	a[i][2]=memo[i][2];	a[i][3]=memo[i][3];
		for(int i=1;i<=n;++i){
			if((a[i][3]>a[i-1][3])&&(b[i]==false)){
				swap(a[i][3],a[i-1][3]);
			}
		}
		for(int k=1;k<=n/2;++k){
			res3+=a[k][3];
			b[k]=true;
		}
			
		sum[l]=res1+res2+res3;
	}
	
	for(int x=1;x<=t;++x) cout<<sum[x]<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
