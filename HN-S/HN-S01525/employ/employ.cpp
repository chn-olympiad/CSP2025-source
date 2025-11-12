#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int a[N],n,m,sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)sum++;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(int i=sum-m+1;i<=sum;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<0;
	return 0;
}
