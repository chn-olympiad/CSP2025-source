#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool v[5005];
long long num;int n;int k;
void dfs(int x,int y,int cnt,int mx)
{
	if(x > k||y > n) {
		if(cnt>mx*2){

			num++;
		}
		return;
	}
	for(int i=y;i<=n;i++){
		if(!v[i]){
			int xs=mx;
			mx=max(mx,a[i]);
			v[i]=1;
			cnt+=a[i];

			dfs(x+1,i,cnt,mx);
			mx=xs;
			cnt-=a[i];

			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	num = 0;
	for(k=3;k<=n;k++){

		dfs(1,1,0,0);
		num%=998244353;                               
	}
	printf("%lld",num);
	return 0;
}













































































