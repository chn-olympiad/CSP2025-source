#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=998244353;
char a[505];
int j(int x){
	int ans=1;
	for(int i=2;i<=x;i++)	ans*=i;
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	int n,m,b=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='1')	b++;
		else	c++;
	}
	if(!b)	cout<<j(n)/j((n-m))%N;
	else if(m==1){
		if(c)	cout<<n;
		else	cout<<0;
	}
	else if(m==n){
		if(b)	cout<<0;
		else	cout<<j(n)%N;
	}
	else	cout<<0;
	return 0;
}
