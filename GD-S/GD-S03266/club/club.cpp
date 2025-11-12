#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+50;
int t,n,ans; 
struct node{
	int a,b,c;
}l[N];
bool fb,fc;
bool cmp(node d1,node d2){
	if(d1.a==d2.a){
		return d1.b>d2.b;
	}
	return d1.a>d2.a;
}
void dfs(int sum,int q,int p,int w,int k){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	if(q<n/2){
		dfs(sum+l[k].a,q+1,p,w,k+1);
	}
	if(p<n/2){
		dfs(sum+l[k].b,q,p+1,w,k+1);
	}
	if(w<n/2){
		dfs(sum+l[k].c,q,p,w+1,k+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		fb=fc=0;
		cin>>n;
		memset(l,0,sizeof(l));
		for(int i=1;i<=n;i++){
			cin>>l[i].a>>l[i].b>>l[i].c;
			if(l[i].b!=0) fb=1;
			if(l[i].c!=0) fc=1;
		}
		if(!fc){
			sort(l+1,l+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=l[i].a;
			}
			if(fb){
				for(int i=n/2+1;i<=n;i++){
					ans+=l[i].b;
				}
			}	
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
