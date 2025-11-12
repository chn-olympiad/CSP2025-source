#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,ans;

struct R{
	int a,b,c;
	int m;
}r[N];

bool C(R x,R y){
	return x.m>y.m;
}

void dfs(int x,int a,int b,int c,int l){
	if(x>=n){
		ans=max(ans,l);
		return;
	}
	if(a<n/2){
		dfs(x+1,a+1,b,c,l+r[x+1].a);
	}
	if(b<n/2){
		dfs(x+1,a,b+1,c,l+r[x+1].b);
	}
	if(c<n/2){
		dfs(x+1,a,b,c+1,l+r[x+1].c);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>r[i].a>>r[i].b>>r[i].c;
			r[i].m=max(r[i].a,max(r[i].b,r[i].c));
		}
		if(n<=10){
			dfs(0,0,0,0,0);
		}else{
			sort(r+1,r+n+1,C);
			for(int i=1;i<=n/2;i++){
				ans+=r[i].m;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
