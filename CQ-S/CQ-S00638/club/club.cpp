#include<bits/stdc++.h>
using namespace std;
int t,n,s,a,b,c,k[3];
priority_queue <int> q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<3;i++){
			while(q[i].size()) q[i].pop();
			s=k[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			int w=max({a,b,c});
			s+=w;
			if(a==w) k[0]++,q[0].push(max(b,c)-a);
			else if(b==w) k[1]++,q[1].push(max(a,c)-b);
			else k[2]++,q[2].push(max(a,b)-c);
		}
		for(int i=0;i<3;i++) while(k[i]>n/2) s+=q[i].top(),q[i].pop(),k[i]--;
		printf("%d\n",s);
	}
	return 0;
}
