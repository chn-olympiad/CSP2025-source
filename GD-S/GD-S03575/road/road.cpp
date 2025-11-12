#include<bits/stdc++.h>
using namespace std;
struct str{
	long long roadx,roady,money;
};
long long fa[1000005];
bool cmp(str a,str b){
	return a.money<b.money;
}
long long find(long long x){
	if(fa[x]==x){
		return x;
	}
	return find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	vector<str> s;
	str u;
	for(long long i=1;i<=m;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		u.roadx=x;
		u.roady=y;
		u.money=z;
		s.push_back(u);
	}
	
	for(long long i=1;i<=k;i++){
		long long mon;
		cin>>mon;
		long long money[n+1];
		for(long long j=1;j<=n;j++){
			long long x;
			cin>>x;
			money[j]=x;
			for(long long h=1;h<j;h++){
				u.roadx=h;
				u.roady=j;
				u.money=mon+x+money[h];
				s.push_back(u);
			}
		}
	}
	sort(s.begin(),s.end(),cmp);
	for(long long i=0;i<=n;i++){
		fa[i]=i;
	}
	long long deep=0;
	long long ans=0;
	for(long long i=0;i<s.size()&&deep<n-1;i++,deep++){
		while(find(s[i].roadx)==find(s[i].roady))i++;
		ans+=s[i].money;
		fa[s[i].roadx]=s[i].roady;
	}
	cout<<ans;
	return 0;
}
