#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010],b[100010],c[100010],m[4],d[4][100010],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;
		m[1]=0,m[2]=0,m[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",a+i,b+i,c+i);
			if(a[i]>=b[i]&&b[i]>=c[i]){
				m[1]++;
				ans+=a[i];
				d[1][m[1]]=a[i]-b[i];
			}else if(a[i]>=c[i]&&c[i]>=b[i]){
				m[1]++;
				ans+=a[i];
				d[1][m[1]]=a[i]-c[i];
			}else if(b[i]>=a[i]&&a[i]>=c[i]){
				m[2]++;
				ans+=b[i];
				d[2][m[2]]=b[i]-a[i];
			}else if(b[i]>=c[i]&&c[i]>=a[i]){
				m[2]++;
				ans+=b[i];
				d[2][m[2]]=b[i]-c[i];
			}else if(c[i]>=a[i]&&a[i]>=b[i]){
				m[3]++;
				ans+=c[i];
				d[3][m[3]]=c[i]-a[i];
			}else{
				m[3]++;
				ans+=c[i];
				d[3][m[3]]=c[i]-b[i];
			}
		}if(m[1]>n/2){
			sort(d[1]+1,d[1]+m[1]+1);
			for(int i=1;i<=m[1]-n/2;i++) ans-=d[1][i];
		}if(m[2]>n/2){
			sort(d[2]+1,d[2]+m[2]+1);
			for(int i=1;i<=m[2]-n/2;i++) ans-=d[2][i];
		}if(m[3]>n/2){
			sort(d[3]+1,d[3]+m[3]+1);
			for(int i=1;i<=m[3]-n/2;i++) ans-=d[3][i];
		}printf("%d\n",ans);
	}
	return 0;
}
