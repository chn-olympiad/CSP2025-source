#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005][5005],ans,m;
int check(int s){
	int cnt=0,f=0,mx=0,p=1;
	while(s){
		if(s&1){
			mx=max(mx,a[p]);
			cnt++;
			f+=a[p];
		}
		s=s>>1;
		p++;
	}
	if(cnt<3||2*mx>=f){
		return 0;
	}
	return 1;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	if(m==1){
		for(int i=1;i<=n+1;i++){
			f[i][1]=1;
			f[i][i]=1;
		}
		for(int i=1;i<=n+1;i++){
			for(int j=2;j<=(i+1)/2;j++){
				f[i][j]=f[i-1][j-1]+f[i-1][j];
				f[i][j]%=998244353;
				f[i][i-j+1]=f[i][j];
			}
		}
		for(int i=4;i<=n+1;i++){
			ans+=f[n+1][i];
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=(1<<n)-1;i++){
		ans+=check(i);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}