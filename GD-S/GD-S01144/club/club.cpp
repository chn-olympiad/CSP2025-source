#include <bits/stdc++.h>
using namespace std;
struct mb{
	int a[5];
	int lc;
	int z1,z2;
}s[100005];
bool cmp(mb const &x,mb const &y){
	if(x.lc>y.lc){
		return true;
	}
	else{
		return false;
	}
}
int jj[5];
int t,n,bi=-1,bg1=0,bg2=0,bi2=-1;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&s[j].a[1],&s[j].a[2],&s[j].a[3]);
			bi=-1;
			bi2=-1;
			for(int k=1;k<=3;k++)
				if(s[j].a[k]>bi){
					bi=s[j].a[k];
					bg1=k;
				}
			for(int k=1;k<=3;k++)
				if(k==bg1){
					continue;
				}
				else{
					if(s[j].a[k]>bi2){
						bi2=s[j].a[k];
						bg2=k;
					}
				}
			s[j].lc=bi-bi2;
			s[j].z1=bg1;
			s[j].z2=bg2;
			//printf("%d %d %d\n",s[j].lc,s[j].z1,s[j].z2);
		}
		sort(s+1,s+n+1,cmp);
		//for(int j=1;j<=n;j++){
		//	printf("%d",s[j].lc);
		//}
		ans=0;
		for(int j=1;j<=3;j++){
			jj[j]=0;
		}
		for(int j=1;j<=n;j++){
			jj[s[j].z1]++;
			if(jj[s[j].z1]>n/2){
				jj[s[j].z1]--;
				jj[s[j].z2]++;
				ans=ans+s[j].a[s[j].z2];
			}
			else{
				ans=ans+s[j].a[s[j].z1];
			}
		}
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
}
