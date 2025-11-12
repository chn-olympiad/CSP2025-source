#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
using namespace std;
ll read(){
	ll k=0;bool flag=1;char c=getchar_unlocked();
	while(!isdigit(c)){if(c=='-')flag=0;c=getchar_unlocked();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar_unlocked();}
	if(flag)return k;else return -k;
}
char readc(){
	char c=getchar_unlocked();
	while(!isgraph(c))c=getchar_unlocked();
	return c;
}
string reads(){
	string str="";char c=getchar_unlocked();
	while(!isgraph(c))c=getchar_unlocked();
	while(isgraph(c)){str+=c;c=getchar_unlocked();}
	return str;
}
const int N=1e5+10;
int n,ans;
struct node{
	int val[5],ma,mid,mi;
}a[N];
void dfs(int p,int A,int B,int C,int now){
	if(p==n+1){
		if(A<=n/2&&B<=n/2&&C<=n/2)ans=max(ans,now);
		return ;
	}
	if(a[p].ma==a[p].val[1])dfs(p+1,A+1,B,C,now+a[p].ma);
	if(a[p].ma==a[p].val[2])dfs(p+1,A,B+1,C,now+a[p].ma);
	if(a[p].ma==a[p].val[3])dfs(p+1,A,B,C+1,now+a[p].ma);
	
	if(a[p].mid==a[p].val[1])dfs(p+1,A+1,B,C,now+a[p].mid);
	if(a[p].mid==a[p].val[2])dfs(p+1,A,B+1,C,now+a[p].mid);
	if(a[p].mid==a[p].val[3])dfs(p+1,A,B,C+1,now+a[p].mid);
	
	if(a[p].mi==a[p].val[1])dfs(p+1,A+1,B,C,now+a[p].mi);
	if(a[p].mi==a[p].val[2])dfs(p+1,A,B+1,C,now+a[p].mi);
	if(a[p].mi==a[p].val[3])dfs(p+1,A,B,C+1,now+a[p].mi);
	return ;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int sum=0,ma=-1e9,mi=1e9;
		for(int j=1;j<=3;++j){
			a[i].val[j]=read();
			sum+=a[i].val[j];
			mi=min(mi,a[i].val[j]);
			ma=max(ma,a[i].val[j]);
		}
		a[i].ma=ma;
		a[i].mid=sum-ma-mi;
		a[i].mi=mi;
	}
	if(n<=13){
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		return ;
	}
	ans=0;
	int A=0,B=0,C=0;
	for(int i=1;i<=n;++i){
		if(a[i].ma==a[i].val[1])++A;
		else if(a[i].ma==a[i].val[2])++B;
		else ++C;
		ans+=a[i].ma;
	}
	if(A<=n/2&&B<=n/2&&C<=n/2){
		cout<<ans<<"\n";
		return ;
	}
	bool flag=0;
	sort(a+1,a+1+n,[](node a,node b){return a.ma-a.mid<b.ma-b.mid;});
	int p;
	for(int i=1;i<=n;++i){
		if(a[i].ma==a[i].val[1])--A;
		else if(a[i].ma==a[i].val[2])--B;
		else --C;
		if(a[i].mid==a[i].val[1])++A;
		else if(a[i].mid==a[i].val[2])++B;
		else ++C;
		ans=ans-a[i].ma+a[i].mid;
		if(A<=n/2&&B<=n/2&&C<=n/2){
			p=i;
			flag=1;
			break;
		}
	}
	if(flag){
		int pos=n,l,r;
		for(l=1,r=p;l<=r;){
			while(l<=r&&a[l].mid-a[l].mi<a[r].ma-a[r].mid){
				if(a[l].mid==a[l].val[1])--A;
				else if(a[l].mid==a[l].val[2])--B;
				else --C;
				if(a[l].mi==a[l].val[1])++A;
				else if(a[l].mi==a[l].val[2])++B;
				else ++C;
				ans-=a[l].mid-a[l].mi;
				
				ans+=a[r].ma-a[r].mid;
				if(a[r].mid==a[r].val[1])--A;
				else if(a[r].mid==a[r].val[2])--B;
				else --C;
				if(a[r].ma==a[r].val[1])++A;
				else if(a[r].ma==a[r].val[2])++B;
				else ++C;
				++l;--r;
				pos=l;
			}
			++l;
		}
		++pos;
		while(pos<=r&&A<=n/2&&B<=n/2&&C<=n/2){
			ans+=a[r].ma-a[r].mid;
			if(a[r].mid==a[r].val[1])--A;
			else if(a[r].mid==a[r].val[2])--B;
			else --C;
			if(a[r].ma==a[r].val[1])++A;
			else if(a[r].ma==a[r].val[2])++B;
			else ++C;
			++pos;
		}
		cout<<ans<<"\n";
		return ;
	}
	cout<<"i can't make it\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)solve();
    return 0;
}
// -std=c++14 -O2 
