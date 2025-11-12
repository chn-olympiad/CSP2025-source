#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct node{
	int fa,pos;
}s[N][3];
int n,t,ans;
int sum[3];
int q[3][N];
int k[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum[0]=sum[1]=sum[2]=ans=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				cin>>s[i][j].fa;
				s[i][j].pos=j;
			}
			if(s[i][0].fa<s[i][1].fa)
				swap(s[i][0],s[i][1]);
			if(s[i][0].fa<s[i][2].fa)
				swap(s[i][0],s[i][2]);
			if(s[i][1].fa<s[i][2].fa)
				swap(s[i][1],s[i][2]);
			ans+=s[i][0].fa;
			int now=s[i][0].pos;
			++sum[now];
			q[now][sum[now]]=s[i][0].fa-s[i][1].fa;
		//	cout<<q[now][i]<<' ';
		}
	/*	
		cout<<n<<"***\n";
		for(int i=1;i<=n;++i){
			cout<<i<<": ";
			for(int j=0;j<3;++j){
				cout<<s[i][j].fa<<' ';
			}
			cout<<'\n';
		}
		for(int j=0;j<3;++j) cout<<sum[j]<<' ';
		cout<<"\n***\n";
	*/
		for(int j=0;j<3;++j){
			if(sum[j]<=n/2) continue;
			for(int i=1;i<=sum[j];++i) k[i]=q[j][i];
			sort(k+1,k+1+sum[j]);
	/*		
			for(int i=1;i<=sum[j];++i){
				cout<<k[i]<<' ';
			}
			cout<<'\n';
	*/	
			for(int i=1;i<=sum[j]-(n/2);++i) ans-=k[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
