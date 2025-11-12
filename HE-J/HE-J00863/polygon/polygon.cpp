#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],al,su,an,ma;
bool f=0;
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				continue;
			}
			al++;
			ma=max(a[i],ma);
			su+=a[i];
		}
		if(su>ma*2&&al>=3){
			an++;
		}
		al=0,su=0,ma=0;
		return ;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f=1;
		}
	}
	if(!f){
		long long as=0;
		for(int i=3;i<=n;i++){
			long long sm=1,ss=1;
			for(int j=1;j<=i;j++){
				sm*=n-j+1;
				ss*=j;
			}
			sm/=ss;
			as+=sm;
		}
		cout<<as%998244353;
		return 0;
	}
	dfs(1);
	cout<<an%998244353;
	return 0;
}
