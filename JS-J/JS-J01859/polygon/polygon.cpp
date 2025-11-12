#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int M=998244353;
struct node{
	int m,l,f;
};
queue<node> q;
int n,a[N],ans,na,k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		na=max(na,a[i]);
	}
	if(na==1){
		for(int i=3;i<=n;i++){
			k=1;
			for(int j=1;j<=i;j++){
				k*=n-j+1;
				k%=M;
				k*=j;
				k%=M;
			}
			ans+=k;
			ans%=M;
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(n<=5000){
		node c;
		node t;
		c.m=0;c.l=0;c.f=0;
		q.push(c);
		while(!q.empty()){
			c=q.front();
			q.pop();
			if(c.m!=n){
				t.m=c.m+1;
				t.l=c.l+a[t.m];
				t.f=max(c.f,a[t.m]);
				q.push(t);
				t.m=c.m+1;
				t.l=c.l;
				t.f=c.f;
				q.push(t);
			}
			else{
				if(c.l>c.f*2){
					ans++;
					ans%=M;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
