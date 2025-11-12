#include<bits/stdc++.h>
using namespace std;
int t,n,flag;
int m[100005][4];
int maxx[100005];
int maxxx[5],sum[5],ans;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int num=n/2;
		int ma=-1e9;
		memset(m,0,sizeof(m));
		memset(maxx,0,sizeof(maxx));
		for(int i=1;i<=n;i++){
			cin>>m[i][1]>>m[i][2]>>m[i][3];
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				sum[i]+=m[j][i];
			}
		}
		if(sum[1]==0&&sum[2]==0){
			for(int i=1;i<=n;i++){
				maxx[i]=m[i][3];
			}
			sort(maxx+1,maxx+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=maxx[i];
			}
			cout<<ans<<endl;
			ans=0;
		}
		if(sum[2]==0&&sum[3]==0){
			for(int i=1;i<=n;i++){
				maxx[i]=m[i][1];
			}
			sort(maxx+1,maxx+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=maxx[i];
			}
			cout<<ans<<endl;
			ans=0;
		}if(sum[1]==0&&sum[3]==0){
			for(int i=1;i<=n;i++){
				maxx[i]=m[i][2];
			}
			sort(maxx+1,maxx+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=maxx[i];
			}
			cout<<ans<<endl;
			ans=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			if(m[i][j]>ma) ma=m[i][j];
			}
			ans+=ma;
			ma=-1e9;
		}
		cout<<ans<<endl;
		ans=0;
}
	return 0;
}
