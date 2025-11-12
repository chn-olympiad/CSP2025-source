#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a1[N],a2[N],a3[N],z1[N],z2[N],z3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		int ans=0,len1=0,len2=0,len3=0,d[N]={};
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				len1++;
				z1[i]=a1[i];
				ans+=a1[i];
				z2[i]=-1;
				z3[i]=-1;
			}	
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				len2++;
				z2[i]=a2[i];
				ans+=a2[i];
				z1[i]=-1;
				z3[i]=-1;
			}
			else{
				len3++;
				z3[i]=a3[i];
				ans+=a3[i];	
				z1[i]=-1;
				z2[i]=-1;
			} 
		}
		if(len1>len2+len3){
			for(int i=1;i<=n;i++){
				if(z1[i]==-1)d[i]=100000;
				else d[i]=z1[i]-max(a2[i],a3[i]);
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=(len1-len2-len3)/2;i++)ans-=d[i];
			printf("%d\n",ans);
		}
		else if(len2>len1+len3){
			for(int i=1;i<=n;i++){
				if(z2[i]==-1)d[i]=100000;
				else d[i]=z2[i]-max(a1[i],a3[i]);
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=(len2-len1-len3)/2;i++)ans-=d[i];
			printf("%d\n",ans);
		}
		else if(len3>len1+len2){
			for(int i=1;i<=n;i++){
				if(z3[i]==-1)d[i]=100000;
				else d[i]=z3[i]-max(a1[i],a2[i]);
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=(len3-len1-len2)/2;i++)ans-=d[i];
			printf("%d\n",ans);	
		}
		else printf("%d\n",ans);
	}
	return 0;
}
