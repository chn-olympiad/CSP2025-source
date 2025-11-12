#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node{int s1,s2,s3;};
int T,n,a[N][5]; ll ans;
bool cmp1(node x,node y){
	return min(x.s1-x.s2,x.s1-x.s3)<min(y.s1-y.s2,y.s1-y.s3);
}
bool cmp2(node x,node y){
	return min(x.s2-x.s1,x.s2-x.s3)<min(y.s2-y.s1,y.s2-y.s3);
}
bool cmp3(node x,node y){
	return min(x.s3-x.s1,x.s3-x.s2)<min(y.s3-y.s1,y.s3-y.s2);
}
void f(vector<node> d,int id){
	if(id==1) sort(d.begin(),d.end(),cmp1);
	if(id==2) sort(d.begin(),d.end(),cmp2);
	if(id==3) sort(d.begin(),d.end(),cmp3);
	for(int i=0;i<(int)d.size()-n/2;i++)
	{
		if(id==1) ans-=min(d[i].s1-d[i].s2,d[i].s1-d[i].s3);
		if(id==2) ans-=min(d[i].s2-d[i].s1,d[i].s2-d[i].s3);
		if(id==3) ans-=min(d[i].s3-d[i].s1,d[i].s3-d[i].s2);
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--&&cin>>n)
	{
		ans=0;
		vector<node> d[5];
		for(int i=1;i<=n;i++)
		{
			int ma=0,id=0;
			for(int j=1;j<=3&&cin>>a[i][j];j++)
				if(ma<a[i][j]) ma=a[i][j],id=j;
			d[id].push_back({a[i][1],a[i][2],a[i][3]});
			ans+=ma;
		}
		if(d[1].size()>n/2) f(d[1],1);
		if(d[2].size()>n/2) f(d[2],2);
		if(d[3].size()>n/2) f(d[3],3);
		cout<<ans<<"\n";
	}
	return 0; 
}
/*
Ren5Jie4Di4Ling5%
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4 
13
*/
