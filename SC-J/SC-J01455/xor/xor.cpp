#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200003],sum,l,v[10003][10003];
int ans;
void s(int m,int x){
	if(m==n+1){
		ans=max(ans,x);
		return;
	}
	sum=0;
	for(int i=m;i<=n;i++){
		sum^=a[i];
		if(sum==k&&v[m][i]==0){
			v[m][i]=1;
			sum=0;
			s(i+1,x+1);
			sum=0;
			break;
		}
	}
	sum=0;
	s(m+1,x);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s(1,0);
	cout<<ans;
	//100+100+40
	return 0;
}
