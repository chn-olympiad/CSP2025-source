#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],c,add=0,b,w[5005],maxn,sum;
void dfs(int k){
	if(c>=3&&add>2*maxn)sum++;
	//cout<<c<<" "<<add<<" "<<maxn<<endl;
	for(int i=k;i<=n;i++){
		w[i]=1;
		int t=maxn;
		maxn=max(maxn,a[i]);
		add+=a[i];
		c++;
		dfs(i+1);
		c--;
		add-=a[i];
		maxn=t;
		w[i]=0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)b++;
	}
	if(b==n){
		sum%= 998244353;
		long long ans=1;
		for(int i=n;i>=3;i--){
			sum+=ans;
			ans*=i;
			ans%=998244353;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	dfs(1);
	cout<<sum;
	return 0;
}
/*
priority_queue<int> q;
bool operator<(SS x)
*/
