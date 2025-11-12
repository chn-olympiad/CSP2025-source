#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int t,n,f[100005][4],a[100005][4],ans,k,p[100005];

void _work(int l){
	for(int i=1;i<=f[0][l];i++){
		int j=f[i][l];
		int x=a[j][l]-a[j][(l+1)%3+1],y=a[j][l]-a[j][l%3+1];
		//cout << a[j][(l+1)%3+1]<<' '<<y <<'\n'; 
		p[i]=min(x,y);
	}
	sort(p+1,p+1+f[0][l]);
	for(int i=1;i<=f[0][l]-k;i++){
		ans-=p[i];
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		memset(f,0,sizeof(f));
		k=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				f[++f[0][1]][1]=i;
				ans+=a[i][1];
			}
			else{
				if(a[i][2]>a[i][3]){
					f[++f[0][2]][2]=i;
					ans+=a[i][2];
				}
				else{
					f[++f[0][3]][3]=i;
					ans+=a[i][3];
				}
			}
		}	
		//cout << ans<<' ';
		if(f[0][1]<=k&&f[0][2]<=k&&f[0][3]<=k){
			printf("%d \n",ans);
		}
		else {
			int l;
			if(f[0][1]>k)l=1;
			if(f[0][2]>k)l=2;
			if(f[0][3]>k)l=3;
			_work(l);
			printf("%d \n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
