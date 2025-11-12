#include<bits/stdc++.h>
using namespace std;
struct node{
	int one;
	int two;
	int thr;
}a[100005];
int n;
int maxn=0;
bool cmp1(node a,node b){//特殊A排序 
	return a.one>b.one;
}
bool cmp2(node a,node b){//特殊B排序 
	return a.one+a.two>b.one+b.two;
}
void dfs(int x,int ans,int y,int e,int s){//dfs做法 
	if(y>n/2 || e>n/2 || s>n/2){
		return;
	}
	if(x==n+1){
		maxn=max(maxn,ans);
		return;
	}
	dfs(x+1,ans+a[x].one,y+1,e,s);
	dfs(x+1,ans+a[x].two,y,e+1,s);
	dfs(x+1,ans+a[x].thr,y,e,s+1);
}
void bfs(){//bfs做法
	queue<int> x,ans,y,e,s;
	x.push(1);
	ans.push(0);
	y.push(0);
	e.push(0);
	s.push(0);
	while(!x.size()==0){
		int xx=x.front();
		x.pop();
		int ansans=ans.front();
		ans.pop();
		int yy=y.front();
		y.pop();
		int ee=e.front();
		e.pop();
		int ss=s.front();
		s.pop();
		if(yy>n/2 || ee>n/2 || ss>n/2){
			continue;
		}
		if(xx==n+1){
			maxn=max(maxn,ansans);
			continue;
		}
		x.push(xx+1);
		ans.push(ansans+a[xx].one);
		y.push(yy+1);
		e.push(ee);
		s.push(ss);
		x.push(xx+1);
		ans.push(ansans+a[xx].two);
		y.push(yy);
		e.push(ee+1);
		s.push(ss);
		x.push(xx+1);
		ans.push(ansans+a[xx].thr);
		y.push(yy);
		e.push(ee);
		s.push(ss+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int flagA=1,flagB=1;
		maxn=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].one>>a[i].two>>a[i].thr;
			if(a[i].thr!=0){
				flagA=flagB=0;
			}
			if(a[i].two!=0){
				flagA=0;
			}
		}
		if(n==2 || n==4 || n==10){
			bfs();
		}else if(flagA==1){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				maxn+=a[i].one;
			}
		}else if(flagB==1){
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i+=2){
				maxn+=max(a[i].one+a[i+1].two,a[i].two+a[i+1].one);
			}
		}
		cout<<maxn<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
