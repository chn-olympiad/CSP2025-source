//GZ-S00374 遵义市第四初级中学 聂宇东
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int a[6][100005][3],max1[6]={INT_MIN};
void dfs(int t,int n,int sum,int q,int j0,int j1,int j2){
	if(q==n){
		if(sum>max1[t] && j0<=n/2 && j1<=n/2 && j2<=n/2){
			max1[t]=sum;
		}	
		return;
	}
	for(int i=0;i<3;i++){
		sum+=a[t][q][i];
		switch(i){
			case 0:dfs(t,n,sum,q+1,j0+1,j1,j2);break;
			case 1:dfs(t,n,sum,q+1,j0,j1+1,j2);break;
			case 2:dfs(t,n,sum,q+1,j0,j1,j2+1);break;
		}
		sum-=a[t][q][i];
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t1;
	cin>>t1;
	int t=0;
	while(t<t1){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[t][i][0]>>a[t][i][1]>>a[t][i][2];
		dfs(t,n,0,0,0,0,0);
		cout<<max1[t]<<endl;
		t++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
