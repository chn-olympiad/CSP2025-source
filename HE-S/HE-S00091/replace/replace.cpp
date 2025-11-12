#include<bits/stdc++.h>
using namespace std;
struct node{
	string s,t;
	int len1;
	int l,r,len;
}a[200005];
int n,q,ans;
bool cmp(node m,node n){
	return m.len<n.len;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
		a[i].l=0;
		a[i].len1=a[i].s.size();
		a[i].r=a[i].len1-1;
		while(a[i].s[a[i].l]==a[i].t[a[i].l])a[i].l++;
		while(a[i].s[a[i].r]==a[i].t[a[i].r])a[i].r--;
		a[i].len=a[i].r-a[i].l+1;
		if(a[i].r<a[i].l)a[i].len=0;
	}
	sort(a+1,a+1+n,cmp);
	string ss,tt;
	while(q--){
		ans=0;
		cin>>ss>>tt;
		if(ss.size()!=tt.size()){
			cout<<0<<"\n";
			continue;
		}
		int siz=ss.size(),f=0,ll=-1,rr=-2;
		for(int i=0;i<siz;i++){
			if(ss[i]!=tt[i]){
				if(!f){
					ll=i;
					f=1;
				}
				rr=i;
			}
		}
		int len2=rr-ll+1;
		if(len2==0){
			for(int i=1;i<=n;i++)
				if(a[i].len==0)
					ans++;
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			f=0;
			if(a[i].len<len2)continue;
			if(a[i].len>len2)break;
			for(int j=0;j<a[i].len1;j++){
				if(j+(ll-a[i].l)>=0 and j+(ll-a[i].l)<siz and a[i].s[j]==ss[j+(ll-a[i].l)] and a[i].t[j]==tt[j+(ll-a[i].l)])continue;
				else f=1;
			}
			if(!f)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
