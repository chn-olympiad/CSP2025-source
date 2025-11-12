#include<bits/stdc++.h>
using namespace std;
int m[5][100001],t,xxx,ans=0,cnt[4];
int mn(int x,int y,int z){
	if(x>=y&&x>=z)return x;
	if(y>=x&&y>=z)return y;
	if(z>=x&&z>=y)return z;
	}
int wz(int x,int y,int z){
	if(x>=y&&x>=z)return 0;
	if(y>=x&&y>=z)return 1;
	if(z>=x&&z>=y)return 2;
	}
 void huan(int k){
	 xxx=m[0][k];
	 m[0][k]=m[0][k+1];
	 m[0][k+1]=xxx;
	 xxx=m[1][k];
	 m[1][k]=m[1][k+1];
	 m[1][k+1]=xxx;
	 xxx=m[2][k];
	 m[2][k]=m[2][k+1];
	 m[2][k+1]=xxx;
	 xxx=m[3][k];
	 m[3][k]=m[3][k+1];
	 m[3][k+1]=xxx;
	 xxx=m[4][k];
	 m[4][k]=m[4][k+1];
	 m[4][k+1]=xxx;
	 }
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int x=1;x<=3;x++)cnt[x]=0;
		ans=0;
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
		cin>>m[0][j]>>m[1][j]>>m[2][j];
		m[3][j]=mn(m[0][j],m[1][j],m[2][j]);
		m[4][j]=wz(m[0][j],m[1][j],m[2][j]);
		}
		for(int x=1;x<=n;x++){
			for(int y=1;y<n;y++){
				if(m[3][y]<m[3][y+1]){	
					huan(y);	
					}
			}
		}
		for(int j=1;j<=n;j++){
			if(cnt[m[4][j]]<n/2){
				ans+=m[3][j];
				cnt[m[4][j]]++;
				}
			else{
				m[m[4][j]][j]=-100;
				m[3][j]=mn(m[0][j],m[1][j],m[2][j]);
				m[4][j]=wz(m[0][j],m[1][j],m[2][j]);
			for(int y=j;y<n;y++){
				if(m[3][y]<m[3][y+1]){	
					huan(y);	
					}
			}
				j--;
			}
		}
		cout<<ans<<"\n";
	}
return 0;
}

