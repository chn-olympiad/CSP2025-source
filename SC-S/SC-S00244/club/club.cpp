#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T;
int n;
int a[N][4];
int mx[N];
int ans=0;
void dfs(int x,int num,int s1,int s2,int s3){
//	printf("%d %d %d %d %d\n",x,num,s1,s2,s3);
	if(x==n){
		ans=max(ans,num);
		return ;
	}
	int s=0;
	for(int i=x+1;i<=n;i++){
		s+=mx[i];
	}
	if(num+s<ans) return;
	dfs(x+1,num,s1,s2,s3);
	if(s1+1<=n/2) dfs(x+1,num+a[x+1][1],s1+1,s2,s3);
	if(s2+1<=n/2) dfs(x+1,num+a[x+1][2],s1,s2+1,s3);
	if(s3+1<=n/2) dfs(x+1,num+a[x+1][3],s1,s2,s3+1);
}
void solve20(){
	ans=0;
	dfs(0,0,0,0,0);
	cout<<ans<<"\n";
}
bool cmp(int x,int y){
	return x>y;
}
void solve12th(){
	ans=0;
	vector<int> g;
	for(int i=1;i<=n;i++){
		g.push_back(a[i][1]);
	}
	sort(g.begin(),g.end(),cmp);
	for(int i=0;i<n/2;i++){
		ans+=g[i];
	}
	cout<<ans<<"\n";
}
int f[105][105][105];
int last[105][105][105];
void solve9_11(){
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int k=0;k<=100;k++){
				f[i][j][k]=0;
				last[i][j][k]=0;
			}
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=min(n/2,i);j>=0;j--){
			for(int k=min(i-j,n/2);k>=0;k--){
				for(int l=min(i-j-k,n/2);l>=0;l--){
//					cout<<f[j][k][l]<<"\n";
					if(j-1>=0) f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+a[i][1]);
					if(k-1>=0) f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[i][2]);
					if(l-1>=0) f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[i][3]);
					
//					cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[j][k][l]<<"\n";
					ans=max(ans,f[j][k][l]);
					last[j][k][l]=f[j][k][l];
				}						
			}
		}
	}
	cout<<ans<<"\n";
}
void solvec(){
	ans=0;
	vector<int> a1,a2,a3;
	for(int i=1;i<=n;i++){
		a1.push_back(a[i][1]);
		a2.push_back(a[i][2]);
		a3.push_back(a[i][3]);
	}
	sort(a1.begin(),a1.end(),cmp);
	sort(a2.begin(),a2.end(),cmp);
	sort(a3.begin(),a3.end(),cmp);
	vector<int> a4;
	for(int i=0;i<n/2;i++){
		a4.push_back(a1[i]);
		a4.push_back(a2[i]);
		a4.push_back(a3[i]);
	}
	sort(a4.begin(),a4.end(),cmp);
	for(int i=0;i<n;i++){
		ans+=a4[i];
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){	
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				mx[i]=max(mx[i],a[i][j]);
			}
		}
//		if(n<=30){
//			solve20();
//			continue;
//		}
		bool s1=1;
		for(int i=1;i<=n;i++){
			if(a[i][2]!=0||a[i][3]!=0){
				s1=0;
			}
		}
		if(s1==1){
			solve12th();
			continue;
		}
		if(n<=200){
			solve9_11();
			continue;
		}
		if(n<=100000){
			solvec();
			continue;
		}
	}
	return 0;
}