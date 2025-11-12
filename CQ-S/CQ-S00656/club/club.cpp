#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,x,y,z,xx,ans,s1,s2,s3;
void solve(){
	priority_queue<int>q1,q2,q3;
	s1=s2=s3=ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		xx=max(x,max(y,z));
		if(xx==x) s1++,q1.push(max(-x+y,-x+z));
		else if(xx==y) s2++,q2.push(max(-y+x,-y+z));
		else s3++,q3.push(max(-z+x,-z+y));
		ans+=xx;
	}
	while(s1>n/2){
		ans+=q1.top();
		q1.pop();
		s1--;
	}
	while(s2>n/2){
		ans+=q2.top();
		q2.pop();
		s2--;
	}
	while(s3>n/2){
		ans+=q3.top();
		q3.pop();
		s3--;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
