#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],sum0[N],sum1[N];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int nn=n;
	for(int i=1;i<=n;i++){
		if(a[i]==0)nn--;
	}
	if(s[0]=='0')sum0[0]=1;
	else sum1[0]=1;
	for(int i=1;i<n;i++){
		sum0[i]=sum0[i-1];
		sum1[i]=sum1[i-1];
		if(s[i]=='0')sum0[i]++;
		else sum1[i]++;
	}
	if(sum1[n-1]<m||nn<m){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		
		cout<<ans;
	}
	return 0;
} 

