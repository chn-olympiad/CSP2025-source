#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}x[100010];
int cmp(node u,node w){
	return u.a<u.a;
}
int cmp1(node u,node w){
	return u.b<u.b;
}
int cmp2(node u,node w){
	return u.c<u.c;
}
int ans1,ans2,ans3,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k=n/2;
		ans1=0;
		ans2=0;
		ans3=0;
		ans=0;
		for (int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		for (int i=1;i<=n;i++){
			int maxn=max(x[i].a,max(x[i].b,x[i].c));
			if(maxn==x[i].a){
				ans+=x[i].a;
				//x[i].a+=1e6;
				ans1++;
			}
			else if(maxn==x[i].b){
				ans+=x[i].b;
				//x[i].b+=1e6;
				ans2++;
			}
			else{
				ans+=x[i].c;
				//x[i].c+=1e6;
				ans3++;
			}
		}
		if(ans1>k){
			sort(x+1,x+n+1,cmp);
			int t=0;
			while(ans1>k){
				int y=x[++t].a;
				int mx=max(x[t].b,x[t].c);
				ans-=y;
				ans+=mx;
				ans1--;
			}
		}
		
		
		if(ans2>k){
			sort(x+1,x+n+1,cmp1);
			int t=0;
			while(ans2>k){
				int y=x[++t].b;
				int mx=max(x[t].a,x[t].c);
				ans-=y;
				ans+=mx;
				ans2--;
			}
		}
		
		
		if(ans3>k){
			sort(x+1,x+n+1,cmp2);
			int t=0;
			while(ans3>k){
				int y=x[++t].c;
				int mx=max(x[t].a,x[t].b);
				ans-=y;
				ans+=mx;
				ans3--;
			}
		}
		cout<<ans<<'\n';
		memset(x,0,sizeof x);
	}
	return 0;
}
