#include<bits/stdc++.h>
using namespace std;
int T,n;
struct abc{
	long long a,b,c;
}a[100005];
long long sum=0;
vector<int>aaa,bbb,ccc;
priority_queue<long long,vector<long long>,greater<long long> >q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,aaa.clear(),bbb.clear(),ccc.clear(),sum=0;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;++i){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c)aaa.emplace_back(i),sum+=a[i].a;
			else if(a[i].b>a[i].c)bbb.emplace_back(i),sum+=a[i].b;
			else ccc.emplace_back(i),sum+=a[i].c; 
		}
		if(aaa.size()*2>n){
			for(auto i:aaa)q.emplace(a[i].a-max(a[i].b,a[i].c));
			int N=aaa.size();
			while(N*2>n)--N,sum-=q.top(),q.pop();
		}
		if(bbb.size()*2>n){
			for(auto i:bbb)q.emplace(a[i].b-max(a[i].a,a[i].c));
			int N=bbb.size();
			while(N*2>n)--N,sum-=q.top(),q.pop();
		}
		if(ccc.size()*2>n){
			for(auto i:ccc)q.emplace(a[i].c-max(a[i].b,a[i].a));
			int N=ccc.size();
			while(N*2>n)--N,sum-=q.top(),q.pop();
		}
		cout<<sum<<"\n";
	}
	return 0;
}
