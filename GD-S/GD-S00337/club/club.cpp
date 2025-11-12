#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10,M=998244353;
int T,n,len;
LL ans;
vector <int> s1,s2,s3;
struct node{
	int f,s,t,id;
}a[N];
bool cmp1(node a,node b){
	return a.f>b.f;
}
void dfs(int l1,int l2,int l3,LL res,int k){
	if(k>n){
		ans=max(ans,res);
//		cout<<res<<endl;
		return ;
	}
		if(l1<len){
//			cout<<res<<" "<<k<<" ";
			dfs(l1+1,l2,l3,res+a[k].f,k+1);
		}
		if(l2<len){
//			cout<<res<<" "<<k<<" ";
			dfs(l1,l2+1,l3,res+a[k].s,k+1);
		}
		if(l3<len){
			
//			cout<<res<<" "<<k<<" ";
			dfs(l1,l2,l3+1,res+a[k].t,k+1);
		}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		len=n/2;
		bool flag=1,flag1=1;
		for(int i=1;i<=n;i++){
			a[i].id=i;
			cin>>a[i].f>>a[i].s>>a[i].t;
			if(a[i].s!=0||a[i].t!=0) flag=0;
			if(a[i].t!=0) flag1=0;
		}
		if(flag){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=len;i++) ans+=a[i].f;
			cout<<ans<<endl;
			continue;
		}
//		if(flag1){
//			dp(1,0,a[1].)
//		}
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
	}
	return 0;
} 
