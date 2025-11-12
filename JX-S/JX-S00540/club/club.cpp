#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
inline void printt(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) printt(x/10);
	putchar(x%10+'0');
}
inline void print(int x){
	printt(x);
	puts("");
}
inline int read(){
	char c;
	int res=0,flag=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			flag=-1;
			c=getchar();
			break;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
const int N=1e5+1;
int T,n,in[N][3],n0,n1,n2,s,s1;
struct node{
	int id,val;
};
node num[N];
std::vector<node> cge;
inline bool cmp(node a,node b){
	return a.val>b.val;
}
inline void solve(int id){
	cge.clear();
	int l,r,nd;
	if(id==0) l=1,r=2;
	else if(id==1) l=0,r=2;
	else l=0,r=1;
	for(int i=1;i<=n;i++){
		if(num[i].id==id) cge.push_back({i,std::max(in[i][l]-in[i][id],in[i][r]-in[i][id])});
	}
	std::sort(cge.begin(),cge.end(),cmp);
	if(id==0) nd=n0-n/2;
	else if(id==1) nd=n1-n/2;
	else if(id==2) nd=n2-n/2;
	for(int i=0;i<nd;i++){
		num[cge[i].id].val+=cge[i].val;
		//s1+=cge[i].val;
		//printf("cgei:%lld,cgeval:%lld,s1:%lld,i:%lld\n",cge[i].id,cge[i].val,s1,i);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		int ans=0;
		n0=0,n1=0,n2=0,s=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&in[i][0],&in[i][1],&in[i][2]);
			num[i].val=std::max(in[i][0],std::max(in[i][1],in[i][2]));
			if(num[i].val==in[i][0]) num[i].id=0,n0++;
			else if(num[i].val==in[i][1]) num[i].id=1,n1++;
			else if(num[i].val==in[i][2]) num[i].id=2,n2++;
		}
		if(n0>n/2) solve(0);
		else if(n1>n/2) solve(1);
		else if(n2>n/2) solve(2);
		for(int i=1;i<=n;i++) ans+=num[i].val;
		print(ans);
		for(int i=1;i<=n;i++) num[i].id=num[i].val=0;
	}
	return 0;
}
