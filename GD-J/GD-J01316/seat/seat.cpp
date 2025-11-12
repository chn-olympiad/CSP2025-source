#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100+5;
int n,m,ans1,ans2;
int a[N],mp[15][15];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	int num=a[1],cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				cnt++;
				mp[j][i]=a[cnt];
				if(a[cnt]==num){
					ans1=j,ans2=i;
				}
			} 
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				mp[j][i]=a[cnt];
				if(a[cnt]==num){
					ans1=j,ans2=i;
				}
			} 
		}
	}
	printf("%lld %lld",ans2,ans1);
	return 0;
}
