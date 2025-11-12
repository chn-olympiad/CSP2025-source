#include<bits/stdc++.h>
using namespace std;
const long long N=505;
const long long mod=998244353;
long long a[N];
const long long M=262145;
long long f[2][19][M];
bool v[N];
long long c[N];
long long b[M];
long long g[M];
vector<long long> h[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	if(n>18){
		printf("0\n");
		return 0;
	}
	long long flag=n+2;
	for(long long i=1;i<=n;i++){
		char c;
		scanf(" %c",&c);
		if(c=='1'){
			v[i]=false;
			if(flag==n+2){
				flag=i-1;
			}
		}
		else{
			v[i]=true;
		}
		b[(1<<(i-1))]=i;
	}
	long long pp=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]>flag){
			pp++;
		}
	}
//	if(m==1){
//		long long qq=1;
//		for(long long i=1;i<n;i++){
//			qq*=i;
//			qq%=mod;
//		}
//		qq*=pp;
//		qq%=mod;
//		printf("%lld\n",qq);
//		return 0;
//	}
	f[0][0][0]=1;
	long long maxx=(1<<n)-1;
	for(long long i=1;i<=maxx;i++){
		g[i]=g[i/2]+(i&1);
		h[g[i]].push_back(i);
//		cout<<i<<":"<<g[i]<<endl;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=i;j++){
			for(auto s:h[i]){
//			for(long long s=1;s<=maxx;s++){
				if(g[s]!=i){
					continue;
				}
				f[i&1][j][s]=0;
//				cout<<s<<":";
				for(long long t=s;t!=0;t=t-(t&(-t))){
					long long u=t&(-t);
					long long k=b[u];
//					cout<<k<<" ";
					if(v[i]==true){
//						cout<<i-j<<" "<<c[k]<<"!";
						f[i&1][j][s]+=f[(i+1)&1][j][s-u];
					}
					else{
						if(j!=0){
							if(i-j<c[k]){
								f[i&1][j][s]+=f[(i+1)&1][j-1][s-u];
							}
						}
						if(i-1-j>=c[k]){
							f[i&1][j][s]+=f[(i+1)&1][j][s-u];
						}
					}
					f[i&1][j][s]%=mod;
				}
//				cout<<endl;
//				cout<<i<<" "<<j<<" "<<s<<" "<<f[i][j][s]<<endl;
				if(i==n&&j>=m){
					ans+=f[i&1][j][s];
					ans%=mod;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
3 1
010
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
