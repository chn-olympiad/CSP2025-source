#include<bits/stdc++.h>
using namespace std;
long long n,a[1005],m,dd[10005],num,mmax,ans;bool f;
int jie(int x){
	int ji=1;
	for(int i = 1;i <= x;i++){
			ji *= i;ji%=998244353;
	}
	if(ji == 0){
		ji = 1;
	}
	return ji;
}
void dfs(int deep){
	if(deep==n+1){
		//cout <<  m << " " << mmax << endl;
		if(m>=3){
			num = 0;
			for (int i = 1;i <= m;i++){
				num += dd[i];
				//cout << dd[i] << " ";
			} 
			//cout << endl;
			if(num > 2*mmax){
				ans+=1;
				
			}
			//cout << endl;
		}
		return;
	}
	dfs(deep+1);
	m+=1;dd[m]=a[deep];int save = mmax;mmax = max(mmax,a[deep]);
	dfs(deep+1);
	m-=1;mmax = save;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	f=1;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f){
		for (int i = 3;i <= n;i++){
			ans+= (jie(n)%998244353/(jie(i)%998244353*jie(n-i)%998244353)%998244353)%998244353;
			ans %=998244353;
			//cout << ans << endl;
		}
	}
	else{
		dfs(1);
	}
	cout << ans%998244353;
	return 0; 
} 

