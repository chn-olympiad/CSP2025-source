//GZ-S00325 贵阳市第一中学 王梓竣 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[505];
int perm[505];
string str;
int a,b,c,n,m,ans,tot,T,k;
int calc(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='0'||sum>=l[perm[i]]){
			sum++;
		}
	}
	return n-sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	str='0'+str;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		perm[i]=i;
	}
	if(calc()>=m){
		ans++;
	}
	while(next_permutation(perm+1,perm+1+n)){
		if(calc()>=m){
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}
