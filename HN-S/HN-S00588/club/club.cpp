#include<bits/stdc++.h>
using namespace std;
int a[100010],sat[100010][3],que[100010],tot=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		int n,club0=0,club1=0,club2=0;
		long long ans=0;
		tot=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&sat[i][0]);
			scanf("%d",&sat[i][1]);
			scanf("%d",&sat[i][2]);
			if(sat[i][0]>=sat[i][1] && sat[i][0]>=sat[i][2]) a[i]=0,club0++;
			else if(sat[i][1]>=sat[i][0] && sat[i][1]>=sat[i][2]) a[i]=1,club1++;
			else a[i]=2,club2++;
			ans+=sat[i][a[i]];
		}
		if(club0<=n/2 && club1<=n/2 && club2<=n/2){
			printf("%d\n",ans);
		}else{
			int w,fill;
			if(club0>n/2) w=0,fill=club0-n/2;
			else if(club1>n/2) w=1,fill=club1-n/2;
			else w=2,fill=club2-n/2;
			for(int i=0;i<n;i++){
				if(a[i]==w){
					int k;
					if(w==0) k=max(sat[i][1],sat[i][2]);
					else if(w==1) k=max(sat[i][0],sat[i][2]);
					else k=max(sat[i][0],sat[i][1]);
					que[tot]=sat[i][w]-k,tot++;
				}
			}
			sort(que,que+tot);
			for(int i=0;i<fill;i++)
				ans-=que[i];
			printf("%d\n",ans);
		}
		t--;
	}
	return 0;
}
