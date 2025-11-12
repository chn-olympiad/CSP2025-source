#include<bits/stdc++.h>
using namespace std;
int a[25],n,tot;
void DFS(int id,int sum,int maxx,int cnt){
	if(id==n+1){
		if(cnt>=3&&sum>maxx*2)tot++;
		return ;
	}
	DFS(id+1,sum,maxx,cnt);
	DFS(id+1,sum+a[id],max(maxx,a[id]),cnt+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>max(a,max(b,c))*2)cout<<1;
		else cout<<0;
	}
	else if(n<=23){
		for(int i = 1;i<=n;i++)cin>>a[i];
		DFS(1,0,0,0);
		cout<<tot;
	}
	else{
		long long ans = 1,s = 2,m = 998244353,n2 = n;
		while(n2){
			if(n2&1)ans = ans*s%m;
			s = s*s%m;
			n2>>=1;
		}
		cout<<((ans-(n+1+n*(n-1)/2)%m)%m+m)%m;
	}
	return 0;
}
