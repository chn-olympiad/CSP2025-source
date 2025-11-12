#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e5+10;
ll T,n,m,ans;
ll a[N][10],b[N],cnt1,cnt2,cnt3;
ll s1[N],s2[N];
struct node{
	ll x,y,f;
	ll id;
}s[N];
bool vis[N];
ll id[N];
ll count(){
	ll res=0;
	for(int i=1;i<=n;i++){
		res+=a[i][b[i]];
	}
	return res;
}
void dfs(ll u){
	if(u>n){
		ans=max(ans,count());
		return ;
	}
	if(cnt1+1<=n/2){
		b[u]=1;
		cnt1++;
		dfs(u+1);
		cnt1--;
	}
	if(cnt2+1<=n/2){
		b[u]=2;
		cnt2++;
		dfs(u+1);
		cnt2--;
	}
	if(cnt3+1<=n/2){
		b[u]=3;
		cnt3++;
		dfs(u+1);
		cnt3--;
	}
}
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0||a[i][3]!=0) return false;
	}
	return true;
}
bool cmp(ll x,ll y){
	if(a[x][1]==a[y][1]) return x<y;
	return a[x][1]>a[y][1];
}
void count1(){
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=a[id[i]][1];
	}
	return ;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i][3]!=0) return false;
	} 
	return true;
}
bool cmp2(node x,node y){
	if(x.x==y.x){
		return x.y<y.y;
	}
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=30){
			cnt1=cnt2=cnt3=0;
			dfs(1);
			cout<<ans<<endl;
		}
		else{
			if(check1()==true){
				count1();
				cout<<ans<<endl;
			}
			if(check2()==true){
				ll sum=0;
				for(int i=1;i<=n;i++){
					s[i].f=i;
					if(a[i][1]>=a[i][2]){
						s[i].x=a[i][1];
						s[i].id=0;
						s[i].y=a[i][2];
					}
					else{
						s[i].x=a[i][2];
						s[i].id=1;
						s[i].y=a[i][1];
					}
				}
				sort(s+1,s+n+1,cmp2);
				ll cnt1=0,cnt2=0;
				for(int i=1;i<=n;i++){
					if(s[i].id==0){
						if(cnt1+1<=n/2){
							sum+=a[s[i].f][1];
							cnt1++;
						}
						else{
							sum+=a[s[i].f][2];
							cnt2++;
						} 
					}
					else{
						if(cnt2+1<=n/2){
							sum+=a[s[i].f][2];
							cnt2++;
						}
						else{
							sum+=a[s[i].f][1];
							cnt1++;
						}
					}
				}
				cout<<sum<<endl;
			}
		}
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
