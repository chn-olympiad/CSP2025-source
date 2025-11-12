#include<bits/stdc++.h>
using namespace std;
const long long N=5010,p=998244353;
long long n,a[N],c[N][N],ans;

void solve1(){
	int m=max(a[1],max(a[2],a[3]));
	if(a[1]+a[2]+a[3]>2*m) ans=1;
}

long long cc(int n,int m){
	long long s=1,vis[5010];
	for(int i=2;i<=m;i++) vis[i]=1;
	int cnt=m-1;
	for(int i=n-m+1;i<=n;i++){
		s*=i;
		for(int j=2;j<=m&&cnt>0;j++){
			if(!vis[j]) continue;
			if(s%j==0){
				s/=j;
				vis[j]=0;
				cnt--;
			}
		}
	} 
	return s%p;
}
void solve2(){
	for(int i=3;i<=n;i++){
		ans+=(cc(n,i)%p);
		ans%p;
	}
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) flag=0;
	}
	if(n<=3) solve1();
	else if(flag) solve2();
	printf("%lld",ans%p);
	return 0;
}

