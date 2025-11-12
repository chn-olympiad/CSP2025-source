#include<bits/stdc++.h>
using namespace std;
int maxn=0,maxi,maxj;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int q;
cin>>q;
for(int i=0;i<q;i++){
	int n,ans=0;
	cin>>n;
	int a[n+1][4];
	int b[4]={0,0,0,0};
	for(int i=1;i<=n;i++)for(int j=1;j<4;j++)cin>>a[i][j];
	while(true){
		for(int i=1;i<=n;i++)for(int j=1;j<4;j++)if(a[i][j]>maxn){
			maxn=a[i][j];
			maxi=i;
			maxj=j;
		}
		if(maxn==0)break;
		if(b[maxj]+1<=n/2){
			b[maxj]++;
			ans+=n;
			for(int j=1;j<4;j++)a[maxi][j]=0;
		}else{
			a[maxi][maxj]=0;
		}
	}
	cout<<ans<<endl;
}
return 0;
}
