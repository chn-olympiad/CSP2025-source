#include<bits/stdc++.h>
using namespace std;
int cj[110],sum[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
			scanf("%d",&cj[i]);
	}
	int R=cj[0],i=0,j=0,j2=0,ans1=0,ans2=0;
	bool b=0,f=0;//0表示↓ 1表示↑ 
	sort(cj,cj+n*m);
	sum[0][0]=cj[n*m-1];
	for(int x=(n*m-1);x>=0;x--){
			sum[i][j]=cj[x];
			if(i==n-1&&f==0){
				if(b)b=0;
				else b=1;
				f=1;
				j++;
			}
			if(!b&&f==0){
				i++;
				
			}
			else if(b&&f==0){
				i--;
			}
			f=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(sum[i][j]==R){
				ans1=j+1,ans2=i+1;
			}
		}
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
