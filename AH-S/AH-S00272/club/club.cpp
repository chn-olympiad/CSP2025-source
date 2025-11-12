#include<bits/stdc++.h>
using namespace std;
int a[3];
priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans,maxn,len;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			maxn=0;
			for(int j=0;j<3;j++){
				scanf("%d",a+j);
				maxn=max(maxn,a[j]);
			}
			ans+=maxn;
			if(a[0]==maxn)q1.push(maxn-max(a[1],a[2]));
			else if(a[1]==maxn)q2.push(maxn-max(a[0],a[2]));
			else q3.push(maxn-max(a[0],a[1]));
		}
		while(!q1.empty()){
			len=q1.size();
			if(len>n/2)ans-=q1.top();
			q1.pop();
		}
		while(!q2.empty()){
			len=q2.size();
			if(len>n/2)ans-=q2.top();
			q2.pop();
		}
		while(!q3.empty()){
			len=q3.size();
			if(len>n/2)ans-=q3.top();
			q3.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
