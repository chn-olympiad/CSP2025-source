#include<bits/stdc++.h>
using namespace std;
const int N=200+5;
int f[205][205][205],n,cl[N][10],ans=0; 
void solve(){
	ans=0;
	memset(f,0,sizeof f);
	memset(cl,0,sizeof cl);
	n=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>cl[i][j];
	for(int i=1;i<=n;i++){
		for(int a1=0;a1<=n;a1++){
			for(int a2=0;a2<=n;a2++){
				
				int a3=i-a1-a2;
				//if(a3>((i+1)/2) || a3<0 || a1>((i+1)/2) || a2>((i+1)/2)) continue;
				if(a3<0) continue;
				//cout<<a1<<" "<<a2<<" "<<a3<<endl;
				if(a1>0) f[a1][a2][a3]=max(f[a1][a2][a3],f[a1-1][a2][a3]+cl[i][1]);
				if(a2>0) f[a1][a2][a3]=max(f[a1][a2][a3],f[a1][a2-1][a3]+cl[i][2]);
				if(a3>0) f[a1][a2][a3]=max(f[a1][a2][a3],f[a1][a2][a3-1]+cl[i][3]);
				if(i==n && a1<=n/2 && a2<=n/2 && a3<=n/2 )ans=max(ans,f[a1][a2][a3]);
				//if(f[a1][a2][a3]==19) cout<<a1<<" "<<a2<<" "<<a3<<endl;
			}
		}
		
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
