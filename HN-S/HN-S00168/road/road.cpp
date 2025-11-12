#include<bits/stdc++.h>
using namespace std;
int n,m,k,a1,a2,a3,cnt,z[100000],ans;
struct node{
	int x,y,v;
};
vector<node> s;
bool cmp(node a,node b){
	return a.v<b.v;
}
int fz(int x){
	if(z[z[x]]!=z[x])
		z[z[x]]=fz(z[x]);
	return z[z[x]];
	return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		cnt=n;
		for(int i=0;i<=n+k;i++)
			z[i]=i;
		for(int i=1;i<=m;i++){
			cin>>a1>>a2>>a3;
			s.push_back({a1,a2,a3});
		}
		sort(s.begin(),s.end(),cmp);
		for(int i=0;cnt!=1;i++){
			if(fz(s[i].x)!=fz(s[i].y)){
				ans+=s[i].v;
				z[fz(s[i].x)]=fz(s[i].y);
				cnt--;
			}
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}

