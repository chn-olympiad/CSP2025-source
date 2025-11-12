#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int v[maxn][4],f[201][201][201],hua_love[maxn],f2[201][201];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(register int i=1;i<=T;i++){
		int n,ans=0,flagA=1,flagB=1;
		cin>>n;
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=3;j++) cin>>v[i][j];
			if(v[i][2]!=0&&v[i][3]!=0) flagA=0;
			if(v[i][3]) flagB=0;
		}
		if(flagA){//Ãÿ ‚–‘÷ A 
			for(register int i=1;i<=n;i++) hua_love[i]=v[i][1];
			sort(hua_love+1,hua_love+1+n,cmp);
			int ans=0;
			for(register int i=1;i<=n/2;i++){
				ans+=hua_love[i];
			} 
			cout<<ans<<"\n";
			continue;
		}
		if(flagB){
			memset(f2,0,sizeof(f2));
			int ans=0;
			for(register int i=1;i<=n;i++){
				for(register int a=n/2;a>=0;a--){
					for(register int b=n/2;b>=0;b--){
						if(a>0) f2[a][b]=max(f2[a-1][b]+v[i][1],f2[a][b]);
						if(b>0) f2[a][b]=max(f2[a][b-1]+v[i][2],f2[a][b]);
						ans=max(ans,f2[a][b]);
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		memset(f,0,sizeof(f));
		for(register int i=1;i<=n;i++){
			for(register int a=n/2;a>=0;a--){
				for(register int b=n/2;b>=0;b--){
					for(register int c=n/2;c>=0;c--){
						if(a>0) f[a][b][c]=max(f[a][b][c],f[a-1][b][c]+v[i][1]);
						if(b>0) f[a][b][c]=max(f[a][b][c],f[a][b-1][c]+v[i][2]);
						if(c>0) f[a][b][c]=max(f[a][b][c],f[a][b][c-1]+v[i][3]);
						ans=max(ans,f[a][b][c]);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
O(n^4) 14:52
try A  14:57
try B(n<200) 15:02
*/
