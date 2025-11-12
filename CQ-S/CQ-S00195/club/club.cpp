#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long flag[100001];
struct node{
	long long id,club1,club2,club3;
}a[300003];
struct Node{
	long long cha,id,from,to;//谁的转移 
}s[300003];
long long c[4];
bool cmp(Node o,Node p){
	return o.cha<p.cha;
}
vector<Node> cha;
//每次都取最大值，对他们的差值排序 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	cin>>t;
	while(t--){
		memset(flag,0,sizeof flag);
		memset(c,0,sizeof c);
		memset(s,0,sizeof s);
		cin>>n;
		long long cnt=0;
		long long num=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].club1>>a[i].club2>>a[i].club3;
			a[i].id=i;
			int ts=max(a[i].club1,max(a[i].club2,a[i].club3));
			int oi=a[i].club1+a[i].club2+a[i].club3;
			int st=min(a[i].club1,max(a[i].club2,a[i].club3));
			int mid=oi-ts-st;
			num+=ts;
			int t1,t2,f;
			if(a[i].club1==ts)c[1]++,f=1;
			if(a[i].club2==ts)c[2]++,f=2;
			if(a[i].club3==ts)c[3]++,f=3;
			if(a[i].club1==mid)t1=1;
			if(a[i].club2==mid)t1=2;
			if(a[i].club3==mid)t1=3;
			if(a[i].club1==st)t2=1;
			if(a[i].club2==st)t2=2;
			if(a[i].club3==st)t2=3;
			cnt++;
			s[cnt].cha=ts-mid;
			s[cnt].from=f;
			s[cnt].id=i;
			s[cnt].to=t1;
			cnt++;
			s[cnt].cha=ts-st;
			s[cnt].from=f;
			s[cnt].id=i;
			s[cnt].to=t2;
		}
		long long ans=0;
		sort(s+1,s+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(c[s[i].from]<=n/2||c[s[i].to]>n/2||flag[s[i].id]==1)continue;
			c[s[i].from]--;
			c[s[i].to]++;
			num-=s[i].cha;
			flag[s[i].id]=1;
		}
		cout<<num<<'\n';
	}
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
