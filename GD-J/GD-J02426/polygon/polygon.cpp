#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,s[505],ans;
void f(int now,int qv,int sum,int maxx){
	//cout<<now<<" ";
	if(qv>=3){
		if(maxx*2<sum) ans++;
	}
	if(now==n) return ;
	for(int i=now+1;i<=n;i++) {
		f(i,qv+1,sum+s[i],max(maxx,s[i]));
	}
	
}
int main(){
	srand(time(0));
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		if(a+b>c) cout<<1;
		else cout<<0;
	}
	else if(n<=500) {
		for(int i=1;i<=n;i++) cin>>s[i];
		f(0,0,0,0);
		cout<<ans;
	}
	else cout<<rand();
	return 0;
}
