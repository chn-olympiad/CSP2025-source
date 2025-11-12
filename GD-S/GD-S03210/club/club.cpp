#include<bits/stdc++.h>
using namespace std;
struct node{
	int t,i;
}b[100005][5];
int t,n,dp[100005],g[5],a[100005];
bool flag=1;
bool cut(node x,node y){
	return x.t>y.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			int a1[5];
			cin>>a1[1]>>a1[2]>>a1[3];
			for(int j=1;j<=3;j++){
				b[i][j].t=a1[j];
				b[i][j].i=j;
			}
			sort(b[i]+1,b[i]+4,cut);
		}
		int h=0;
		dp[0]=0;
		g[1]=0;
		g[2]=0;
		g[3]=0;
		flag=1;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]+b[i][1].t;
			if(g[b[i][1].i]==n/2){
				if(flag==1){
					for(int j=1;j<=n;j++){
						if(b[i][1].i!=b[j][1].i){
							continue;
						}
						a[++h]=b[j][1].t-b[j][2].t;
					}
					sort(a+1,a+h+1);
					flag=0;
					h=0;
				}
				dp[i]-=a[++h];
			}else{
				g[b[i][1].i]++;
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
