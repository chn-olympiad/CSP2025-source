#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
const int N=1e5+10;
struct node{
	int val,num;
}aa[N],bb[N];
int a[N],b[N],c[N];
int sum=0;
void dfs(int val,int x,int sa,int sb,int sc){
	if(x==n) {
		sum=max(sum,val);
		return;
	}
	
	
	if(sa<n/2){
		dfs(val+a[x+1],x+1,sa+1,sb,sc);
	}
	if(sb<n/2){
		dfs(val+b[x+1],x+1,sa,sb+1,sc);
	}
	if(sc<n/2){
		dfs(val+c[x+1],x+1,sa,sb,sc+1);
	}
}
bool cmp(node x,node y){
	return x.val>y.val;
}
bool r=false,r1=false;
unordered_map<int,int>m;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i]>>c[i];	
	aa[i].num=i;
	bb[i].num=i;
	aa[i].val=a[i];
	bb[i].val=b[i];
	if(c[i]!=0) r1=true;
	if(b[i]!=0||c[i]!=0) r=true;
	}
	
	if(r==false){
		sort(a+1,a+1+n);
		for(int i=1;i<=n/2;i++) ans+=a[i];
		cout<<ans<<endl;
		continue;		
	}
	else if(r1==false){
		m.clear();
		sort(aa+1,aa+1+n,cmp);
		sort(bb+1,bb+1+n,cmp);
//		int ans=0;
		int sa=0,sb=0;
		for(int i=1;i<=n;i++){
			if(aa[i].num==bb[i].num){
			if(aa[i].val>bb[i].val&&sa<n/2) sa++,ans+=aa[i].val;
			else ans+=bb[i].val,sb++;;
			continue;	
			}
			
		if(m[aa[i].num]!=1&sa<n/2){
			m[aa[i].num]=1;
			ans+=aa[i].val;
			sa++;
		}
		if(m[bb[i].num]!=1&&sb<n/2){
			sb++;
			ans+=bb[i].val;
		}
		}
		cout<<ans<<endl;
		continue;
	}
	
	
	sum=0;
	dfs(a[1],1,1,0,0);
	ans=max(ans,sum);
	sum=0;
	dfs(b[1],1,0,1,0);
	ans=max(ans,sum);
	sum=0;
	dfs(c[1],1,0,0,1);
	cout<<max(ans,sum)<<endl;
	}
	
	
	
	
	
	
	
	
	return 0;
}
