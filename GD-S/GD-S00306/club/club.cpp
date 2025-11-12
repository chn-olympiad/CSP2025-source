#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n, a[N][3], cnt[3];
int dp[N][3][8];
int f(int i, int d, int st){//第i个人准备进入d部门,三个部门人满未满的情况为st 
	if(i==n+1)
		return 0;
//	if(dp[i][d][st]!=-1){
//		return dp[i][d][st];
//	}
	cnt[d]++;int t=st;
	if(cnt[d]==n/2)
		t|=(1<<d);
	int f1=0;
	for(int j=0; j<3; j++)
		if(!(t&(1<<j)))
			f1=max(f1, f(i+1, j, t));
	dp[i][d][st]=f1+a[i][d];
	cnt[d]--;
	return f1+a[i][d];
}
int c[3];
int t1[N], out;
struct str{
	int x, y, ca;
}t2[N];
bool cmp(str x, str y){
	return x.ca<y.ca;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>T;
	while(T--){
		cin>>n;c[0]=c[1]=c[2]=0;
		for(int i=1; i<=n; i++)
			for(int j=0; j<3; j++){
				cin>>a[i][j];
				if(!a[i][j])
					c[j]++;
			}
		if(c[1]==n || c[2]==n){
			if(c[1]==n){
				for(int i=1; i<=n; i++)	
					t1[i]=a[i][0];
				sort(t1+1, t1+1+n);
				out=0;
				for(int i=n; i>n/2; i--)
					out+=t1[i];
				cout<<out<<endl;
			}else{
				out=0;
				for(int i=1; i<=n; i++){
					out+=a[i][1];
					t2[i]={a[i][0], a[i][1], a[i][1]-a[i][0]};
				}
				sort(t2+1, t2+1+n, cmp);
				for(int i=1; i<=n/2; i++)
					out-=t2[i].ca;
				cout<<out<<endl;
			}
				continue;
		}
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1; i<=n; i++)	
			for(int j=0; j<3; j++)
				for(int k=0; k<8; k++)
					dp[i][j][k]=-1;
		cout<<max(f(1, 0, 0), max(f(1, 1, 0), f(1, 2, 0)))<<endl;
	}
	return 0;
}
