#include<bits/stdc++.h>
using namespace std;
int n,m,a[120];
int z[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int cj=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1;
	int sum=n*m;
	int mo=1;
	for(;1;){
		z[y][x]=a[sum];
		if(sum==0){
			break;
		}
		
		sum--;
		if(y==n||y==1){
			if(y==1&&x==1){
				y++;
			}
			else{
				if(z[y-1][x]||z[y+1][x]){
					x++;
			        mo++;
				}else{
					if(mo%2==1){
				       y++;
			        }else{
				        y--;
			       }
				}
			}
		}else{
			if(mo%2==1){
				y++;
			}else{
				y--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(z[i][j]==cj){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0; 
}
