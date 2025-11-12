#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ok=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][2]!=0||a[i][3]!=0) ok=1;
		}
		if(n==2){
			int x=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			int y=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			int z=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			cout<<max(x,max(y,z))<<endl;
		}else if(n==4){
			int cnt=0,ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int q=1;q<=3;q++){
						for(int o=1;o<=3;o++){
							int s[5]={0,0,0,0,0};
							s[i]++;
							s[j]++;
							s[q]++;
							s[o]++;
							bool flag=0;
							for(int r=1;r<=3;r++){
								if(s[r]>2) flag=1; 
							}
							if(flag==0){
								cnt=a[1][i]+a[2][j]+a[3][q]+a[4][o];
								ans=max(ans,cnt);
							}
						}
					}
				}
			}
			printf("%d\n",ans);
		}else if(ok==0){
			for(int i=1;i<=n;i++){
				p[i]=a[i][1];
			}
			sort(p+1,p+n+1);
			int ans=0;
			for(int i=n;i>=n/2;i--){
				ans+=p[i];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
