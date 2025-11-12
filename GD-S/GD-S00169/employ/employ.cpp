#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
const int N=5000;
int n,m,c[N],s[N];
bool cmp(int a,int b){return a<b;} 
//void work11(){
//	long long ans=1,js=0;
//	for(int i=1;i<=n;i++) if(c[i]==0) js++;
//	for(int i=1;i<=n;i++)
//		ans=(ans*i)%MOD;
//	cout<<ans;
//	return ;
//}
/*

	int map[N][N];
	memset(map,0,sizeof(map))
	int js=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			cnt++;
			for(int j=1;j<=n;j++){
				if(c[i]>=i) map[cnt][i]++;
				else map[cnt][i-c[j]]++;
			}
		}
	}
	for(int i=2;i<=n;i++){
		map[i][1]+=map[i-1][1];
		for(int j=2;j<=n;j++){
			map[i][j]+=map[i][j-1];
		}
	}
*/
int x[N],add[N];
void workm1(){
	
	int js=0,jss=0;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			jss++;
			for(int j=1;j<=n;j++){
				if(c[j]>=i) x[jss]++;
			}
		}
	}
	for(int i=1;i<=jss;i++) cout<<x[i]<<endl;
	long long jc=1,ans=0;
	for(int i=1;i<=n-jss;i++){
		jc=(jc*i)%MOD;
	}
	for(int i=jss;i>=1;i--){
		int ans1=1;
		ans1+=jc;
		for(int j=jss-1;j>=1;j--){
			ans1*=(n-x[j]);
			ans1%MOD;
		} 
		js*=(n-i+1);
		ans+=ans1;
//		cout<<ans1<<endl;
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string ss;
	cin>>ss;
	int js=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		s[i]=ss[i-1]-'0';
		if(s[i]<js) js=s[i];
	}
//	if(js==1){
//		work11();
//	}
	if(m==1){
		workm1();
	}
//	sort(c+1,c+1+n,cmp);
	
	return 0;
}
