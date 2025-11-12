#include<bits/stdc++.h>

using namespace std;
using LL = long long;
LL n,m,x,R;
vector<LL> ans;
bool cmp(const LL &lhs,const LL &rhs){
	return lhs>rhs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	
	for(LL i=1;i<=n*m;i++){
		scanf("%lld",&x);
		if(i==1)	R=x;
		ans.push_back(x);
	}
	sort(ans.begin(),ans.end(),cmp);
	LL len=ans.size();
	LL idx=0,c=1;
	while(idx<len){
		for(LL r=1;r<=n;r++)
			if(ans[idx]==R){printf("%lld %lld",c,r);return 0;}
			else idx++;
		c++;
		if(idx>=len)	break;
		for(LL r=n;r>=1;r--)
			if(ans[idx]==R){printf("%lld %lld",c,r);return 0;}
			else idx++;
		c++;
	}
	return 0;
}
