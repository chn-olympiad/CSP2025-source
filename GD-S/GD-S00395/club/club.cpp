#include<bits/stdc++.H>
using namespace std;
int a[100010][3],x[100010],cnt[3],g[100010],u[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		memset(x,0,sizeof x);
		memset(cnt,0,sizeof cnt);
		memset(g,0,sizeof g);
		memset(u,0,sizeof u);
		int n;
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				cin>>a[i][j];
			}
			int maxnn=0,maxt;
			for(int j=0;j<=2;j++){
				if(a[i][j]>=maxnn){
					maxnn=a[i][j];
					maxt=j;
				}
			}
			sum+=maxnn;
			x[i]=maxt;
			cnt[maxt]++;
		}
		int c=-1;
		for(int i=0;i<=2;i++){
			if(cnt[i]>n/2){
				c=i;
			}
		}
		int qw=0;
		for(int i=1;i<=n;i++){
			if(x[i]==c){
				qw++;
				if(c==0){
					u[qw]=max(a[i][2],a[i][1])-a[i][0];
				}
				if(c==1){
					u[qw]=max(a[i][2],a[i][0])-a[i][1];
				}
				if(c==2){
					u[qw]=max(a[i][0],a[i][1])-a[i][2];
				}
			}
		}
		sort(u+1,u+qw+1);
		for(int i=qw;i>n/2;i--){
			sum+=u[i];
		}
		cout<<sum<<endl;
	}
} 

