#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long 
int T,n,cl[N][5],club[N],cnt[5],ans,t[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a>=b&&a>=c){
			if(b>=c) club[i]=b-a;
			else club[i]=c-a;
			cl[++cnt[1]][1]=i;
			ans+=a;
		}
		else if(b>=a&&b>=c){
			if(a>=c) club[i]=a-b;
			else club[i]=c-b;
			cl[++cnt[2]][2]=i;
			ans+=b;
		}
		else{
			if(a>=b) club[i]=a-c;
			else club[i]=b-c;
			cl[++cnt[3]][3]=i;
			ans+=c;
		}
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
			for(int j=1;j<=cnt[i];j++){
				t[j]=club[cl[j][i]];				
			}
			sort(t+1,t+n+1,greater<int>());
			for(int j=1;j<=cnt[i]-n/2;j++){
				ans+=t[j];
			}
		}
	}
	cout<<ans<<'\n';ans=0;
	for(int i=1;i<=n;i++){
		club[i]=t[i]=0;
		cl[i][1]=cl[i][2]=cl[i][3]=0;
	}
	cnt[1]=cnt[2]=cnt[3]=0;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}








