#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;
struct node{
	int a,b,c,d,e;
}s[maxn];
vector<node>a,b,c;
bool cmp1(node x,node y){
	if(x.a==y.a){
		if(x.b==y.b) return x.c<y.c;
		return x.b<y.b;
	}
	return x.a>y.a;
}
bool cmp2(node x,node y){
	if(x.b==y.b){
		if(x.a==y.a) return x.c<y.c;
		return x.a<y.a;
	}
	return x.b>y.b;
}
bool cmp3(node x,node y){
	if(x.c==y.c){
		if(x.a==y.a) return x.b<y.b;
		return x.a<y.a;
	}
	return x.c>y.c;
}
int t,n,flag1,flag2;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		flag1=1,flag2=1;
		cin>>n;
		a.clear();
		b.clear();
		c.clear();
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0) flag1=0;
			if(s[i].c!=0){
				flag1=0;
				flag2=0;
			}
			s[i].d=min(min(s[i].a,s[i].b),s[i].c);
			s[i].a-=s[i].d;
			s[i].b-=s[i].d;
			s[i].c-=s[i].d;
		}
		if(flag1&&flag2){
			sort(s+1,s+1+n,cmp1);
			int sum=0;
			for(int i=1;i<=n/2;i++) sum+=s[i].a;
			cout<<sum<<"\n";
			continue;
		}
		if(flag2){
			int sum=0;
			for(int i=1;i<=n;i++){
				s[i].e=min(s[i].a,s[i].b);
				s[i].a-=s[i].e;
				s[i].b-=s[i].e;
			}
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=n/2;i++) sum+=s[i].a;
			for(int i=n/2+1;i<=n;i++) sum+=s[i].b;
			for(int i=1;i<=n;i++) sum+=s[i].e;
			cout<<sum<<"\n";
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=s[i].d;
			if(s[i].a==0){
				if(s[i].b==s[i].c&&s[i].b!=0){
					if(b.size()<=c.size()) b.push_back(s[i]);
					else c.push_back(s[i]);
				}
				if(s[i].b!=s[i].c){
					if(s[i].b>s[i].c) b.push_back(s[i]);
					else c.push_back(s[i]);
				}
			}else if(s[i].b==0){
				if(s[i].a==s[i].c&&s[i].a!=0){
					if(a.size()<=c.size()) a.push_back(s[i]);
					else c.push_back(s[i]);
				}
				if(s[i].a!=s[i].c){
					if(s[i].a>s[i].c) a.push_back(s[i]);
					else c.push_back(s[i]);
				}
			}else if(s[i].c==0){
				if(s[i].b==s[i].a&&s[i].b!=0){
					if(b.size()<a.size()) b.push_back(s[i]);
					else a.push_back(s[i]);
				}
				if(s[i].b!=s[i].a){
					if(s[i].b>s[i].a) b.push_back(s[i]);
					else c.push_back(s[i]);
				}
			}
		}
		sort(a.begin(),a.end(),cmp1);
		sort(b.begin(),b.end(),cmp2);
		sort(c.begin(),c.end(),cmp3);
		if(a.size()>n/2){
			for(int i=0;i<n/2;i++) sum+=a[i].a;
			for(int i=n/2;i<a.size();i++){
				int maxl=max(a[i].b,a[i].c);
				if(maxl==a[i].b) b.push_back(a[i]);
				else c.push_back(a[i]);
			}
			for(int i=0;i<b.size();i++) sum+=b[i].b;
			for(int i=0;i<c.size();i++) sum+=c[i].c;
		}else if(b.size()>n/2){
			for(int i=0;i<n/2;i++) sum+=b[i].b;
			for(int i=n/2;i<b.size();i++){
				int maxl=max(b[i].a,b[i].c);
				if(maxl==b[i].a) a.push_back(b[i]);
				else c.push_back(b[i]);
			}
			for(int i=0;i<a.size();i++) sum+=a[i].a;
			for(int i=0;i<c.size();i++) sum+=c[i].c;
		}else if(c.size()>n/2){
			for(int i=0;i<n/2;i++) sum+=c[i].c;
			for(int i=n/2;i<c.size();i++){
				int maxl=max(c[i].a,c[i].b);
				if(maxl==c[i].a) a.push_back(c[i]);
				else b.push_back(c[i]);
			}
			for(int i=0;i<a.size();i++) sum+=a[i].a;
			for(int i=0;i<b.size();i++) sum+=b[i].b;
		}else{
			for(int i=0;i<a.size();i++) sum+=a[i].a;
			for(int i=0;i<b.size();i++) sum+=b[i].b;
			for(int i=0;i<c.size();i++) sum+=c[i].c;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
