#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int a[N][4],n,s[4];
int ans=0;
int d[4][N],l[4];
void solve(){
	cin>>n;
	ans=0;
	l[1]=l[2]=l[3]=s[1]=s[2]=s[3]=0;
	for(int i=1;i<=n;i++){
		int d1=0,d2=0;a[i][0]=-1;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>a[i][d1])d2=d1,d1=j;
			else if(a[i][j]>a[i][d2])d2=j;
		}
		s[d1]++;
		ans+=a[i][d1];
		d[d1][++l[d1]]=-a[i][d1]+a[i][d2];
	}
	int p=0;
	for(int i=1;i<=3;i++)if(s[i]>(n>>1))p=i;
	if(p){
		sort(d[p]+1,d[p]+1+l[p]);
		int k=s[p]-(n>>1);
		for(int i=l[p];i>=l[p]-k+1;i--)ans+=d[p][i];
	}
	cout<<ans<<"\n";
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}
