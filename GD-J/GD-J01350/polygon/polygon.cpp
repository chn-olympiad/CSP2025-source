#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
int n;
int a[N],ans,sum[N];
void dfs(int b,int num,int s,int ma){
	if(s==0){
		if(num>ma&&b>2){
			ans++;
			if(ans>mod) ans-=mod;
		}
		return;
	}else{
		dfs(b,num,s-1,ma);
	    dfs(b+1,num+=a[s],s-1,ma);
	}	
	return;
}
bool fg=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			fg=false;
		}
	}
	if(fg==true){
		ans=1;
		long long l=1,c;
		for(int i=3;i<=n;i++){
			l=1;
			c=1;
			for(int j=1;j<=n-i;j++){
				c*=j;
				l*=(i-j+1);
				l%=mod;
				ans+=l/c;
				ans%=mod;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){sum[i]=sum[i-1]+a[i];}
	for(int i=3;i<=n;i++){
		if(a[i]*2>=sum[i]){
			continue;
		}
		dfs(1,a[i],i-1,a[i]*2);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
