#include<bits/stdc++.h>
using namespace std;
int a[100002][4];
long long f[100001][4][4];
int k[100001][4][4],last[100001][4];
int n,t;
int dp()
{
	for(int i=1;i<=n;i++){
		int c,c1,c2;
		for(int j=1;j<=3;j++){//当前目标 
			for(int h=1;h<=3;h++){//i-1选的 
			    k[i][j][h]=max(k[i][j][h],k[i-1][h][last[i-1][h]]);
				if(k[i-1][j][last[i-1][h]]>=n/2) continue;
				if(f[i][j][h]<=f[i-1][h][last[i-1][h]]+a[i][j]){
					f[i][j][h]=f[i-1][h][last[i-1][h]]+a[i][j];
					last[i][j]=h;
					c1=h;
					k[i][j][h]=k[i-1][h][last[i-1][h]]+1;
				}
				//k[i][j][c1]++;
			}
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t){
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dp();
		t--;
		long long maxx=-1;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				maxx=max(maxx,f[n][i][j]);
			}
		}
		cout<<maxx;
		for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=3;j++){
    			k[i][j][1]=k[i][j][2]=k[i][j][3]=0;
    		    f[i][j][1]=f[i][j][2]=f[i][j][3]=0;
			}
		}
	}
	return 0;
}
