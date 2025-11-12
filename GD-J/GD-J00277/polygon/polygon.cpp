#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int n,a[N];
long long ans;
int zuhe(int o,int p){
	int tmp=o,cnt=1;
	for(int i=1;i<=p;i++){
		cnt=cnt*tmp%MOD;
		tmp--;
	}for(int i=p;i>1;i--){
		cnt=cnt/i%MOD;
	}return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		ans=(ans+zuhe(n,i))%MOD;
	}cout<<ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
