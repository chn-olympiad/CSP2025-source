#include<bits/stdc++.h>
using namespace std;
struct line{
	int to,num;
};
struct line2{
	int a,b,num;
};
line2 flag[100005];
vector<line> s[10005];
int cnt[100005];
int fflag[1000005];
bool cmp(line2 a,line2 b){
	return a.num>b.num;
}
bool ff(int a){
	if(fflag[a]!=a){
		fflag[a]=ff(fflag[a]);
	}
	return fflag[a];
} 
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fflag[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		s[a].push_back(line{b,c});
		flag[i]=line2{a,b,c};
	} 
	for(int i=1;i<=k;i++){
		cin>>cnt[i];
		for(int j=1;j<=n;j++){
			int h;
			cin>>h;
			s[i+n].push_back(line{j,h});
			flag[i+m]=line2{i+n,j,h};
		}
	}
	int ans=0;
	sort(flag+1,flag+1+m+k*n,cmp);
	for(int i=1;i<=1+m+k*n;i++){
	 	if(ff(flag[i].a)!=ff(flag[i].b)){
	 		fflag[ff(flag[i].a)]=ff(flag[i].b);
	 		ans=ans+flag[i].num;
		}
	}
	cout<<ans;
	return 0;
}
