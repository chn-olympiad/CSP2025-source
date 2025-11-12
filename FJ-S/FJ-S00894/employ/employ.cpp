#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m;
string s;
int c[510];
int pl[510];
int dp[510];
long long ans,es,pe;
long long jc(int n){
	long long re=1;
	for(int i=2;i<n;i++){
		re*=i;re%=p;
	}
	return re;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		pl[i]=i+1;
	}
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i+1];
	}
	do{
		es=0,pe=0;
		for(int i=0;i<n;i++){
			if(es<c[pl[i]]&&s[i]=='1')pe++;
			else {
				es++;//cout<<s[i]<<" "<<es<<" "<<pl[i]<<" "<<c[pl[i]]<<" "<<i+1<<endl;
			}
			if(pe>=m)break;
			if(i+m-pe>n)break;
		}
		if(pe>=m)ans++;
		ans%=p;
	//	cout<<endl;
	}while(next_permutation(pl,pl+n));
	cout<<ans;
	return 0;
}
