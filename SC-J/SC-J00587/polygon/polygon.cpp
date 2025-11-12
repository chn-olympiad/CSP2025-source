#include<bits/stdc++.h>
using namespace std;
int a[5007];
int s[507][50007];
const int N=998244353;
int main(){
	memset(s,0,sizeof s);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if(a[n]==1){
		int x=1;
		for(int i=1;i<=n;i++){
			x*=2;
			x%=N;
		}
		x--;
		x-=n;
		x-=n*(n-1)/2;
		cout << ((x%N)+N)%N;
	}
	else{
		s[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<50003;j++){
				if(j<a[i]) s[i][j]=s[i-1][j];
				else s[i][j]=(s[i-1][j]+s[i-1][j-a[i]])%N;
			}
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			for(int j=a[i]+1;j<50003;j++){
				ans+=s[i-1][j];
				ans%=N;
			}
		}
		cout << ans;
	}
	return 0;
}