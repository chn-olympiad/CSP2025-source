#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][3],rs[3],id[3],f[1005][1005]={0},dp[3],suma,sumb;
void q(int x,int y,int z){
	if(x>=y&&x>=z){
		id[0]=0;
		if(y>=z){id[1]=1;id[2]=2;}
		else{id[1]=2;id[2]=1;}
	}
	if(y>x&&y>=z){
		id[0]=1;
		if(x>=z){id[1]=0;id[2]=2;}
		else{id[1]=2,id[2]=0;}
	}
	if(z>x&&z>y){
		id[0]=2;
		if(x>=y){id[1]=0;id[2]=1;}
		else{id[1]=1,id[2]=0;}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		suma=0;sumb=0;
		for(int i=0;i<3;i++)rs[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			q(a[i][0],a[i][1],a[i][2]);
			for(int j=0;j<3;j++){
				int x=id[j];
				if(rs[x]>=n/2){
					continue;
				}
				else{
					suma+=a[i][x];
					rs[x]++;
					break;
				}
			}
		}
		for(int i=n;i>=1;i--){
			q(a[i][0],a[i][1],a[i][2]);
			for(int j=0;j<3;j++){
				int x=id[j];
				if(rs[x]>=n/2){
					continue;
				}
				else{
					sumb+=a[i][x];
					rs[x]++;
					break;
				}
			}
		}
		cout<<max(suma,sumb)<<endl;
	}
	return 0;
}
