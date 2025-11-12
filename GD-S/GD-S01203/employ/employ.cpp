#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
string s;
int a[N];
long long ans;
long long C(int i,int j){
	long long l=1,c=1;
	for(int x=1;x<=i;x++){
		c*=x;
		l*=(j-x+1);
	}
	return (l/c)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int tp=1;
	for(int i=n;i>=m;i--){
		while(!(a[tp]>n-i)){
			tp++;
		}
		if(n-tp+1<i) continue;
		ans+=C(i,n-tp+1);
		//cout<<i<<" "<<n-tp+1<<" "<<C(i,n-tp+1)<<endl;
		ans%=mod;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
