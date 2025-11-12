#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
struct node{
	int m,l,f;
};
queue<node> q;
int n,k,a[N],ans,na;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		na=max(na,a[i]);
	}
	if(na<=1){
		if(k>=2){
			ans=0;
		}
		else{
			if(k==1){
				for(int i=1;i<=n;i++){
					if(a[i]==1){
						ans++;
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(a[i]==0){
						ans++;
					}
					else{
						if(a[i-1]==1){
							ans++;
							a[i]=0;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(n<=N){
		node c;
		node t;
		c.m=0;c.l=0;c.f=0;
		q.push(c);
		while(!q.empty()){
			c=q.front();
			q.pop();
			if(c.m!=n){
				t.m=c.m+1;
				t.l=c.l^a[t.m];
				t.f=c.f;
				if(t.l==k){
					t.f++;
					t.l=0;
				}
				if(t.f+n-t.m>ans){
					q.push(t);
				}
				t.m=c.m+1;
				t.l=c.l;
				t.f=c.f;
				if(t.f+n-t.m>ans){
					q.push(t);
				}
			}
			else{
				ans=max(ans,c.f);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
