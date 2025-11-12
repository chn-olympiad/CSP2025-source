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
int n,q,ans;
string sub,t,str,a[N],b[N];
void dfs(string s,int dep){
	if(dep>1)return ;
	if(s==t){
		++ans;
		return ;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<s.size();++j){
			sub=s.substr(j,10000000);
			if(sub.find(a[i])==string::npos)continue;
			str=sub;
			int pos=sub.find(a[i]);
			str=s;
			for(int k=0;k<a[i].size()&&k+pos<sub.size();++k)str[k+pos]=b[i][k];
			//if(str=="b")cout<<i<<" "<<j<<" "<<"\n";
			dfs(str,dep+1);
		}
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
	for(int i=1;i<=q;++i){
		string s;
		cin>>s>>t;
		ans=0;
		dfs(s,0);
		cout<<ans<<"\n";
	}
    return 0;
}
// -std=c++14 -O2 
