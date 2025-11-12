#include<bits/stdc++.h>
using namespace std;
int t,a[100001][11],n,ans=0;
int asd(int aa,int b,int c,int cnt,int j){
	if(cnt>n){
		if(aa<=n/2&&b<=n/2&&c<=n/2){
			ans=max(ans,j);
			return 0;
		}else{
			//cout<<1<<' ';
			return 0;
		}
	}
	asd(aa+1,b,c,cnt+1,j+a[cnt][1]);
	asd(aa,b+1,c,cnt+1,j+a[cnt][2]);
	asd(aa,b,c+1,cnt+1,j+a[cnt][3]);	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int o=asd(0,0,0,1,0);
		ans=max(ans,o);
		cout<<ans<<endl;
	}
	return 0;
}
