#include<bits/stdc++.h>
using namespace std;
int n,a1[100005],a2[100005],a3[100005],ans;
int f[105][105][105];
void solve(){
	scanf("%d",&n);
	ans=0;
	int mi;
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
//		mi=min({a[i][1],a[i][2],a[i][3]});
//		ans+=mi;
//		a[i][1]-=mi,a[i][2]-=mi,a[i][3]-=mi; 
	}
	if(n>200){
		sort(a1+1,a1+1+n);
		for(int i=1;i<=n/2;i++){
			ans+=a1[i];
		}
		cout<<ans<<endl;
		return;
	}
	for(int k=1;k<=n;k++){
		for(int i=min(k,n/2);i>=0;i--){
			for(int j=min(k,n/2);j>=0;j--){
				for(int g=min(n-i-j,n/2);g>=0;g--){
					if(i>=1)f[i][j][g]=
					max(f[i-1][j][g]+a1[k],f[i][j][g]);
					if(j>=1)f[i][j][g]=
					max(f[i][j-1][g]+a2[k],f[i][j][g]);
					if(g>=1)f[i][j][g]=
					max(f[i][j][g-1]+a3[k],f[i][j][g]);
				}	
			}			
		}
	}
//	for(int i=0;i<=n/2;i++){
//		for(int j=0;j<=n/2;j++){
//			for(int g=0;g<=n/2&&(i+j+g)<=n;g++){
//				cout<<i<<":"<<j<<':'<<g<<':'<<f[i][j][g]<<'\n';
//			}	
//		}			
//	}
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			if(n-i-j<=n/2)
				ans=max(ans,f[i][j][n-i-j]);
		}
	}
	cout<<ans<<endl;
	return; 
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	} 
	return 0;
}
/*E2
147325
125440
152929
150176
158541*/
/*E3
447450
417649
473417
443896
484387

*/
