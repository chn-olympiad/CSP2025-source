#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1000;
int t,n,a[N][5],ans,aa[N],bb[N],cc[N],acnt,bcnt,ccnt;
int f(int y){
	if(a[y][1]>a[y][2]){
		if(a[y][1]>a[y][3])return 1;
		else return 3;
	}
	else{
		if(a[y][2]>a[y][3])return 2;
		else return 3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		ans=0;
		acnt=0;
		bcnt=0;
		ccnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			int x=f(i),z;	
			ans+=a[i][x];
			if(x==1){
				if(a[i][2]>a[i][3])z=2;
				else z=3;
				aa[++acnt]=a[i][x]-a[i][z];
			}
			else if(x==2){
				if(a[i][1]>a[i][3])z=1;
				else z=3;
				bb[++bcnt]=a[i][x]-a[i][z];
			}
			else{
				if(a[i][1]>a[i][2])z=1;
				else z=2;
				cc[++ccnt]=a[i][x]-a[i][z];
			}
		}
		int nn=n/2;
		if(acnt>nn){
			sort(aa+1,aa+acnt+1);
			for(int i=1;i<=acnt-nn;i++){
				ans-=aa[i];
			}
		}
		if(bcnt>nn){
			sort(bb+1,bb+bcnt+1);
			for(int i=1;i<=bcnt-nn;i++){
				ans-=bb[i];
			}
		}
		if(ccnt>nn){
			sort(cc+1,cc+ccnt+1);
			for(int i=1;i<=ccnt-nn;i++){
				ans-=cc[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
