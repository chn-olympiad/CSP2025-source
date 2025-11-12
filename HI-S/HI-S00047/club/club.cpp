#include<bits/stdc++.h>
using namespace std;
int n,a[100002][5],k,y,e,s,sum,ma,yb[100005],eb[100005],sb[100005];
int cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("cluc.out","w",stdout);
	int t;	
	scanf("%d",&t);
	while(t--){
		sum=0;
		y=0;
		e=0;
		s=0;
		scanf("%d",&n);
		k=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(j==1){
					yb[i]=a[i][j];
				}
				if(j==2){
					eb[i]=a[i][j]; 
				} 
				else{
					sb[i]=a[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				y++;
				ma=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				e++;
				ma=a[i][2];
			}
			else{
				s++;
				ma=a[i][3];
			}
			//cout<<ma<<" ";
			sum+=ma;
		}
		if(y>k){
			int yyb[100055];
			for(int i=1;i<=n;i++){
				yyb[i]=yb[i];
			} 
			sort(yyb+1,yyb+n+1,cnt);
			int u1=yyb[k+1],u2=yyb[y];
			for(int i=1;i<=n;i++){
				if(yb[i]>=u2&&yb[i]<=u1){
					y--;
					if(eb[i]==max(eb[i],sb[i])){
						e++;
						sum-=yb[i];
						sum+=eb[i];
					}
					else{
						s++;
						sum-=yb[i];
						sum+=sb[i];
					}
				}
			}
		}
		if(e>k){
			int eeb[100055];
			for(int i=1;i<=n;i++){
				eeb[i]=eb[i];
			} 
			sort(eeb+1,eeb+n+1,cnt);
			int u1=eeb[k+1],u2=eeb[e];
			for(int i=1;i<=n;i++){
				if(eb[i]>=u2&&eb[i]<=u1){
					e--;
					if(yb[i]==max(yb[i],sb[i])){
						y++;
						sum-=eb[i];
						sum+=yb[i];
					}
					else{
						s++;
						sum-=eb[i];
						sum+=sb[i];
					}
//					cout<<sum<<" "<<i<<"\n";
				}
			}
		}
		if(s>k){
			int ssb[100055];
			for(int i=1;i<=n;i++){
				ssb[i]=sb[i];
			} 
			sort(ssb+1,ssb+n+1);
			int u1=ssb[k+1],u2=ssb[s];
			for(int i=1;i<=n;i++){
				if(sb[i]>=u2&&sb[i]<=u1){
					s--;
					if(eb[i]==max(yb[i],eb[i])){
						e++;
						sum-=sb[i];
						sum+=eb[i];
					}
					else{
						y++;
						sum-=sb[i];
						sum+=yb[i];
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
