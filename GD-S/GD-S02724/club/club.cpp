#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ll long long

#define For(a,b,c) for(int a=(b);a<=(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(c);a--)

int read() {
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9'; ch=getchar()) x=(x*10)+ch-'0';
	return x*f;
}

#define in1(a) a=read()
#define in2(a,b) a=read(),b=read()
#define in3(a,b,c) a=read(),b=read(),c=read()
#define in4(a,b,c,d) a=read(),b=read(),c=read(),d=read()

const int maxn=100050;

int n;
struct node {
	int a[3];
}a[maxn];

bool cmp(node a,node b) {
	return max({a.a[0],a.a[1],a.a[2]})>max({b.a[0],b.a[1],b.a[2]});
}


void work() {
	in1(n); int ans=0;
	For(i,1,n) in3(a[i].a[0],a[i].a[1],a[i].a[2]);
	
	sort(a+1,a+n+1,cmp);
	
	int cnt[3]={0,0,0};
	For(i,1,n) {
		ans+=max({a[i].a[0],a[i].a[1],a[i].a[2]});
		if(a[i].a[0]>a[i].a[1]&&a[i].a[0]>a[i].a[2]) cnt[0]++;
		if(a[i].a[1]>a[i].a[0]&&a[i].a[1]>a[i].a[2]) cnt[1]++;
		if(a[i].a[2]>a[i].a[0]&&a[i].a[2]>a[i].a[1]) cnt[2]++;
	}
	
	int mx=-1;
	if(cnt[0]>n/2) mx=0;
	if(cnt[1]>n/2) mx=1;
	if(cnt[2]>n/2) mx=2;
	
	if(mx==-1) return cout<<ans<<'\n',void();
	if(mx!=0) For(i,1,n) swap(a[i].a[0],a[i].a[mx]);
	vector<int> x;
	For(i,1,n) if(a[i].a[0]>a[i].a[1]&&a[i].a[0]>a[i].a[2]) x.push_back(a[i].a[0]-max(a[i].a[1],a[i].a[2]));
	sort(x.begin(),x.end()); int idx=0;
	For(i,(n/2)+1,cnt[mx]) ans-=x[idx],idx++;
	cout<<ans<<'\n';
}


signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int _=read();
	while(_--) work(); 
	
	
	return 0;
}
/*
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

*/
