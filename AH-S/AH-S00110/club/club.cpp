#include<bits/stdc++.h>
#define rd read()
#define el putchar('\n')
#define QAQ printf("QAQ");
using namespace std;
typedef long long ll;

ll read(){
	char ch=getchar();
	ll x=0,flag=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			flag=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*flag;
}
void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
}

const ll MAXN=1e5+5,inf=1e18,mod=1e9+7;
ll n,ans;
struct node{
	int x,y,z;
}a[MAXN];
bool cmpa(node a,node b){
	return a.x>b.x;
}
bool cmpb(node a,node b){
	return abs(a.x-a.y)>abs(b.x-b.y);
}
bool cmp(node a,node b){
	return abs(a.x-a.z)+abs(a.y-a.z)+abs(a.x-a.y)>abs(b.x-b.z)+abs(b.y-b.z)+abs(b.x-b.y);
}
void dfs(ll now,ll sum,ll cnt1,ll cnt2,ll cnt3){
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1+1<=n/2){
		dfs(now+1,sum+a[now].x,cnt1+1,cnt2,cnt3);
	}
	if(cnt2+1<=n/2){
		dfs(now+1,sum+a[now].y,cnt1,cnt2+1,cnt3);
	}
	if(cnt3+1<=n/2){
		dfs(now+1,sum+a[now].z,cnt1,cnt2,cnt3+1);
	}
}
void solve(){
	n=rd;
	ll sum2=0,sum3=0;
	ans=0;
	for(int i=1;i<=n;i++){
		a[i].x=rd;
		a[i].y=rd;
		a[i].z=rd;
		sum2=sum2+a[i].y;
		sum3=sum3+a[i].z;
	}
	if(sum2==0&&sum3==0){
		sort(a+1,a+n+1,cmpa);
		for(int i=1;i<=n/2;i++){
			ans=ans+a[i].x;
		}
		write(ans);el;
		return ;
	}
	if(n<=10){
		dfs(1,0,0,0,0);
		write(ans);el;
		return ;
	}
	if(sum3==0){
		sort(a+1,a+n+1,cmpb);
		for(int i=1,cnt1=0,cnt2=0;i<=n;i++){
			if(a[i].x<a[i].y){
				if(cnt2+1<=n/2){
					cnt2++;
					ans=ans+a[i].y;
				}else{
					cnt1++;
					ans=ans+a[i].x;
				}
			}else{
				if(cnt1+1<=n/2){
					cnt1++;
					ans=ans+a[i].x;
				}else{
					cnt2++;
					ans=ans+a[i].y;
				}
			}
		}
		write(ans);el;
		return ;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1,cnt1=0,cnt2=0,cnt3=0;i<=n;i++){
		if(a[i].x<a[i].y){
			if(a[i].y<a[i].z){
				if(cnt3+1<=n/2){cnt3++;ans=ans+a[i].z;}
				else if(cnt2+1<=n/2){cnt2++;ans=ans+a[i].y;}
				else{cnt1++;ans=ans+a[i].x;}
			}else if(a[i].z>a[i].x&&a[i].z<=a[i].y){
				if(cnt2+1<=n/2){cnt2++;ans=ans+a[i].y;}
				else if(cnt3+1<=n/2){cnt3++;ans=ans+a[i].z;}
				else{cnt1++;ans=ans+a[i].x;}
			}else{
				if(cnt2+1<=n/2){cnt2++;ans=ans+a[i].y;}
				else if(cnt1+1<=n/2){cnt1++;ans=ans+a[i].x;}
				else{cnt3++;ans=ans+a[i].z;}
			}
		}else{
			if(a[i].z>a[i].x){
				if(cnt3+1<=n/2){cnt3++;ans=ans+a[i].z;}
				else if(cnt1+1<=n/2){cnt1++;ans=ans+a[i].x;}
				else{cnt2++;ans=ans+a[i].y;}
			}else if(a[i].z<=a[i].x&&a[i].z>a[i].y){
				if(cnt1+1<=n/2){cnt1++;ans=ans+a[i].x;}
				else if(cnt3+1<=n/2){cnt3++;ans=ans+a[i].z;}
				else{cnt2++;ans=ans+a[i].y;}
			}else{
				if(cnt1+1<=n/2){cnt1++;ans=ans+a[i].x;}
				else if(cnt2+1<=n/2){cnt2++;ans=ans+a[i].y;}
				else{cnt3++;ans=ans+a[i].z;}
			}
		}
			
	}
	write(ans);el;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=rd;
	while(T--){
		solve();
	}
	return 0;
}
