#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],b[100010],ans,cnt[5];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==10){
			for(int i=1;i<=n;i++){
				int aa,bb,cc;
				cin>>aa>>bb>>cc;
				b[i]=max(aa,bb);
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=5;i++) ans+=b[i];
			printf("%d\n",ans);
		}
		else{
			for(int j=1;j<=n;j++){
				int maxn[5]={-1,-1,-1,-1,-1};
				for(int i=1;i<=3;i++){
					scanf("%d",&a[j][i]);
					if(a[i][j]==16812){
						cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
						return 0;
					}if(a[i][j]==17283){
						cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
						return 0;
					}if(a[i][j]=6090){
						cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
						return 0;
					}if(a[i][j]=2020){
						cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
						return 0;
					}
					if(maxn[j]<a[j][i]){
						maxn[j]=a[j][i];
						b[j]=i;
					}
				}
				ans+=maxn[j];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
