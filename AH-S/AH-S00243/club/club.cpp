#include<bits/stdc++.h>
using namespace std;
struct ren{
	int a,b,c;
}s[100005];
int t,n,fz,ns,v[100005],ii;
bool A,B;
bool cmp(ren x,ren y){return x.a>y.a;}
int dfs(int ans,int na,int nb,int nc,int ii){
	if(na>n/2||nb>n/2||nc>n/2)return -1;
	if(ii>n){return ans;}
	return max(dfs(ans+s[ii].a,na+1,nb,nc,ii+1),max(dfs(ans+s[ii].b,na,nb+1,nc,ii+1),dfs(ans+s[ii].c,na,nb,nc+1,ii+1)));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		A=1;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0||s[i].c!=0)A=0;
		}
		if(A){
			sort(s,s+1+n,cmp);
			for(int i=1;i<=n/2;i++)ns+=s[i].a;
			cout<<ns<<endl;
			continue;
		}
		cout<<dfs(0,0,0,0,1)<<endl;
	}
	return 0;
}
