#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;

int n,m;
string s;
int c[N],p[N];
//int sum[N],m;
//int f[1<<18][20],pc[1<<18];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
//	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++)if(i-1-cnt<c[p[i]]&&s[i-1]=='1')cnt++;
			if(cnt>=m)ans++;	
		}while(next_permutation(p+1,p+1+n));
		cout<<ans;
//		return 0;
//	}
//	int cnt=0;
//	for(int i=1;i<=n;i++)if(s[i-1]=='0')cnt++;else sum[++m]=cnt;
//	if(n<=18){
//		for(int i=1;i<(1<<18);i++){
//			int j=i,ct=0;
//			while(j){
//				ct+=j%2;
//				j/=2;
//			}
//			pc[i]=ct;
//		}
//		f[0][0]=1;
//		for(int i=1;i<(1<<18);i++)
//			for(int j=0;j<=pc[i];j++)
//				for(int k=0;k<=)
//	}
	return 0;
}
