#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],maa,mia,b[100005],x,c[4],ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		c[1]=c[2]=c[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			maa=0,mia=20000;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>=maa)maa=a[i][j];
				if(a[i][j]<=mia)mia=a[i][j];
			}
			for(int j=1;j<=3;j++)
				if(a[i][j]!=mia&&a[i][j]!=maa){
				a[i][0]=maa-a[i][j];
				break;
				}
		}
		for(int i=1;i<=n;i++){
			maa=0;
			for(int j=1;j<=3;j++)
				if(a[i][j]>=maa)maa=a[i][j],x=j;
				c[x]++,ans+=maa;
		}
		for(int i=1;i<=3;i++){
			while(c[i]>n/2){
				mia=20000;
				for(int j=1;j<=n;j++)
					if(a[j][0]<=mia&&a[j][i]>=a[j][1]&&a[j][i]>=a[j][2]&&a[j][i]>=a[j][3])
						mia=a[j][0],x=j;
				c[i]--,ans-=a[x][0],a[x][0]=20000;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
