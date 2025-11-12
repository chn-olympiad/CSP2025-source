#include<bits/stdc++.h>
using namespace std;

int const N = 1e5+10;
bool st[3];
int a[N],b[N],c[N],n,cnt,a1 = 0,b1 = 0,c1 = 0,ans = 0;
void dfs(int x){
	ans = max(ans,cnt);
	if(x>n){
		return;
	}
	if(a1<n/2||!st[1]){
			cnt += a[x];
			a1+=1;
			x+=1;
			dfs(x);
			x-=1;
			a1-=1;
			cnt-=a[x];
			
	}
	if(b1<n/2||!st[2]){	
			st[1] = true;
			cnt += b[x];
			b1+=1;
			x+=1;
			dfs(x);
			x-=1;
			b1-=1;
			cnt-=b[x];
		
	}
	if(c1<n/2){
			st[2] = true;
			cnt += c[x];
			c1+=1;
			x+=1;
			dfs(x);
			x-=1;
			c1-=1;
			cnt-=c[x];
		
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans = 0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
