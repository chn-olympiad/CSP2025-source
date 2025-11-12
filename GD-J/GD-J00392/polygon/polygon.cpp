#include<bits/stdc++.h>
using namespace std;

int mod=998244353;
int n,a[5010]={0};
long long ans=0;
struct nn{
	int a,b,c,d;
	bool e;
};
void bfs(){
	queue<nn> q;
	q.push({0,0,0,0,false});
	while(!q.empty()){
		nn t=q.front();
		q.pop();
		if(t.a<=n){
			if(t.d>=3&&t.b>t.c*2&&!t.e){
				ans=(ans+1+mod)%mod;
			}
			q.push({t.a+1,t.b+a[t.a+1],max(t.c,a[t.a+1]),t.d+1,false});
			q.push({t.a+1,t.b,t.c,t.d,true});
		}
	}
	return;
}
long long f(int x){
	long long l=0;
	for(int i=3;i<=n;i++){
		long long a=1,b=1;
		for(int j=0;j<i;i++)
			a*=n-j;
		for(int j=1;i<=i;j++)
			b*=j;
		l=(l+a/b+mod)%mod;
	}
	return l;
} 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int ma=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(a[i],ma);
	}
	if(ma==1){
		cout<<f(n);
	}
	else{
		bfs();
		cout<<ans;	
	}
	
	return 0;
} 
