#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define MN  100100
#define ll long long

struct pa{
	int a,b;
}sz[MN][3];

//int cho[MN];
int ch[3];
inline bool cmp(const pa&a,const pa&b){
	return a.a>b.a;
}

priority_queue<int> pq;

int main1(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>sz[i][0].a>>sz[i][1].a>>sz[i][2].a;
		sz[i][0].b=0;
		sz[i][1].b=1;
		sz[i][2].b=2;
		sort(sz[i],sz[i]+3,cmp);
	}
	ch[0]=ch[1]=ch[2]=0;

	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ans+=sz[i][0].a;
		ch[sz[i][0].b]++;
	}
	int d = -1;
	if(ch[0]>(n/2))d=0;
	else if(ch[1]>(n/2))d=1;
	else if(ch[2]>(n/2))d=2;

	if(d>=0){
		for(int i = 1;i<=n;i++){
			if(sz[i][0].b==d)pq.push(sz[i][1].a-sz[i][0].a);
		}
		for(int i = 0;i<ch[d]-(n/2);i++){
			ans+=pq.top();
			pq.pop();
		}
	}
	while(pq.size())pq.pop();
	cout<<ans<<'\n';

	return 0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin>>T;
	while(T--)main1();


	return 0;
}

