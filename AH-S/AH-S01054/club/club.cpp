#include<bits/stdc++.h>
using namespace std;
int t,n,x1=0,x2=0,x3=0,ans=0,a1[100005],a2[100005],a3[100005];
int b1[100005],b2[100005],b3[100005];
bool used[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		memset(b3,0,sizeof(b3));
		memset(used,0,sizeof(used));
		x1=0,x2=0,x3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a1[i]=x,a2[i]=y,a3[i]=z;
			b1[i]=x,b2[i]=y,b3[i]=z;
		}
		sort(a1+1,a1+n+1);
		sort(a2+1,a2+n+1);
		sort(a3+1,a3+n+1);
		for(int i=n;i>=1;i--){
			for(int j=1;j<=n;j++){
				if(a1[i]==b1[j]&&used[j]==0&&x1<=n/2&&a1[i]!=0){
					used[j]=1;
					ans+=a1[i];
					x1++;
				}
				if(a2[i]==b2[j]&&used[j]==0&&x2<=n/2&&a2[i]!=0){
					used[j]=1;
					ans+=a2[i];
					x2++;
				}
				if(a3[i]==b3[j]&&used[j]==0&&x3<=n/2&&a3[i]!=0){
					used[j]=1;
					ans+=a3[i];
					x3++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
