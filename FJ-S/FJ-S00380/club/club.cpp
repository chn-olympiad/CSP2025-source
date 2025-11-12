#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,t,sum,a[N][4];
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
	return ;
}
inline void dfs(int dep,int p,int b,int c,int s){
	if(dep>n){
		sum=max(s,sum); 
		return ;
	}
	if(p<n/2){
		dfs(dep+1,p+1,b,c,s+a[dep][1]);
		//cout<<1;
	}
	if(b<n/2){
		dfs(dep+1,p,b+1,c,s+a[dep][2]);
		//cout<<2;
	}
	if(c<n/2){
		dfs(dep+1,p,b,c+1,s+a[dep][3]);
		//cout<<3;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		priority_queue<int,vector<int>,greater<int> >q;
		int cnt[4]={0};
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(n<=10)continue;
			if(i>n/2){
				if(a[i][1]>q.top()){
					sum-=q.top();
					q.pop();
					q.push(a[i][1]);
					sum+=a[i][1];
				}
			}else{
				q.push(a[i][1]);
				sum+=a[i][1];
			}
		}
		if(n<=10){
			sum=0;
			dfs(1,0,0,0,0);
		}
		print(sum);
		putchar(10);
	}
	return 0;
}
