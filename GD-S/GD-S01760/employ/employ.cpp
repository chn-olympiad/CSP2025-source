#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,sum,c[505],num[505];
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		num[i]=i;
	}
	do{
		sum=0;
		for(int i=1;i<=n;i++){
			if(i-1-sum<c[num[i]]&&s[i]=='1'){
				sum++;
			}
		}
		if(sum>=m){
			ans=(ans+1)%mod;
		}
	}while(next_permutation(num+1,num+n+1));
	cout<<ans;
	return 0;
}
