#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],s[5005],cnt;
int m_d(int s,int i,int q,int b){
	if(s<=a[i]) return 0;
	int ans=1;
	for(int j=q;j<i;j++){
		if(b>3) ans+=m_d(s-a[j],i,j+1,b-1);
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		cnt=(m_d(s[i-1],i,1,i)+cnt)%998244353;
	}
	cout<<cnt;
	return 0;
}
