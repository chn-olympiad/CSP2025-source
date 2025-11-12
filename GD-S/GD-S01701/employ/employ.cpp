#include<bits/stdc++.h>
#define int long long
#define mod 998224353
using namespace std;
int n,m;
string s;
int num[505],a[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		num[i]=i;
	}
	int ans=0;
	do{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||cnt>=a[num[i]]){
				cnt++;
			}
			if(n-cnt<m)break;
		}
		if(n-cnt>=m)ans++,ans%=mod;
	}while(next_permutation(num+1,num+n+1));
	cout<<ans;
	return 0;
}
//employ
