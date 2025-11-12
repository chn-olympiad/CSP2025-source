#include<bits/stdc++.h>
using namespace std;
long long jx[5010];
const long long h = 998244353;
//jx[n] = n!
int n;
long long ans;
long long qwe;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	jx[1]=1;

	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;

	if((a[1] + a[2]) > a[3])ans++;
	if((a[1] + a[3]) > a[2])ans++;
	if((a[2] + a[3]) > a[1])ans++;
	cout<<ans;
	return 0;
} 
//buhui,kaibai(qwq)
