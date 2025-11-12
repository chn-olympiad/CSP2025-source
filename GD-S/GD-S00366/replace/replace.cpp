#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+3;
int n,m;
struct node{
	string a,b;
	int len;
}s[maxn];
bool cmp(node x,node y){
	return x.len<y.len;
}
int find(int x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(s[mid].len<x)
			l=mid+1;
		else
			r=mid;
	}
	return l;
}
bool check1(string a,string b,int p){
	int cnt=0;
	for(int i=p;i<b.size()+p;i++){
		if(a[i]!=b[cnt])
			return 0;
		else 
			cnt++;
	}
	return 1;
}
bool ask(int a,string x,string y,string y1,int len,int l1){
	string ss=s[a].a,ss1=s[a].b;
	for(int i=0;i<s[a].len;i++){
		if(ss[i]==x[0]){
			if(check1(ss,x,i)){
				//cout<<ss<<endl;
				int l=l1-i;
				int r=l+s[a].len-1;
			///	cout<<l<<" "<<r<<endl;
				if(l<0||r>len)
					return 0;
				string ll;
				for(int i=0;i<len;i++){
					if(i==l){
						i=l;
						ll+=ss1;
					}
					else if(i!=r){
						ll+=y1[i];
					}
				}
				if(ll==y)
					return 1;
				else
					return 0;
			}
		}
	}
	return 0;
}
int check(string x,string y){
	int len=x.size(),l,r; 
	for(int i=0;i<len;i++){
		if(x[i]!=y[i]){
			l=i;
			break;
		}
	}
	for(int i=len-1;i>=0;i--){
		if(x[i]!=y[i]){
			r=i;
			break;
		}
	}
	string xx,yy;
	for(int i=l;i<=r;i++){
		xx+=x[i];
		yy+=y[i];
	}
	int t=find(r-l+1),ans=0;
	//cout<<t<<endl;
	for(int i=t;i<=n;i++){
		if(ask(i,xx,y,x,x.size(),l)){
			ans++;
		}
	}
	return ans;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].len=s[i].a.size();
	}
	sort(s+1,s+1+n,cmp);
	while(m--){
		string x,y;
		cin>>x>>y;
		cout<<check(x,y)<<endl;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	solve();
	return 0;
} 
