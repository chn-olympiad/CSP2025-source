#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
void read(int &n){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
void read(ll &n){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
const int N=1e5+5;
int t,n,a[N][4];
struct node{
	int w,id;
	friend bool operator<(const node a,const node b){
		return a.w<b.w;
	}
}tmp;
int bel[N];
priority_queue<node>q12,q13,q21,q23,q31,q32;
il void add(int x,int id){
	tmp.id=x;
	if(id==1){
		tmp.w=a[x][2]-a[x][1];q12.push(tmp);
		tmp.w=a[x][3]-a[x][1];q13.push(tmp);
	}else if(id==2){
		tmp.w=a[x][1]-a[x][2];q21.push(tmp);
		tmp.w=a[x][3]-a[x][2];q23.push(tmp);
	}else{
		tmp.w=a[x][1]-a[x][3];q31.push(tmp);
		tmp.w=a[x][2]-a[x][3];q32.push(tmp);
	}
}
il void solve(){
	while(!q12.empty())q12.pop();
	while(!q13.empty())q13.pop();
	while(!q21.empty())q21.pop();
	while(!q23.empty())q23.pop();
	while(!q31.empty())q31.pop();
	while(!q32.empty())q32.pop();
	ll ans=0,cnt1=0,cnt2=0,cnt3=0;
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i][1]);read(a[i][2]);read(a[i][3]);
	}
	for(int i=1;i<=n/2;i++){
		cnt1++;ans+=a[i][1];bel[i]=1;
		add(i,1);
	}
	for(int i=n/2+1;i<=n;i++){
		cnt2++;ans+=a[i][2];bel[i]=2;
		add(i,2);
	}
//	cout<<114514;
	bool fl=0;
	do{
//		cout<<fl<<endl;
		fl=0;
		while(!q12.empty()&&bel[q12.top().id]!=1)q12.pop();
		while(!q13.empty()&&bel[q13.top().id]!=1)q13.pop();
		while(!q21.empty()&&bel[q21.top().id]!=2)q21.pop();
		while(!q23.empty()&&bel[q23.top().id]!=2)q23.pop();
		while(!q31.empty()&&bel[q31.top().id]!=3)q31.pop();
		while(!q32.empty()&&bel[q32.top().id]!=3)q32.pop();
		if(cnt1&&cnt2+1<=n/2&&q12.top().w>0){
			int x=q12.top().id;bel[x]=2;ans=ans-a[x][1]+a[x][2];q12.pop();
			cnt1--;cnt2++;
			add(x,2);fl=1;continue;
		}
		if(cnt1&&cnt3+1<=n/2&&q13.top().w>0){
			int x=q13.top().id;bel[x]=3;ans=ans-a[x][1]+a[x][3];q13.pop();
			cnt1--;cnt3++;
			add(x,3);fl=1;continue;
		}
		if(cnt2&&cnt1+1<=n/2&&q21.top().w>0){
			int x=q21.top().id;bel[x]=1;ans=ans-a[x][2]+a[x][1];q21.pop();
			cnt2--;cnt1++;
			add(x,1);fl=1;continue;
		}
		if(cnt2&&cnt3+1<=n/2&&q23.top().w>0){
			int x=q23.top().id;bel[x]=3;ans=ans-a[x][2]+a[x][3];q23.pop();
			cnt2--;cnt3++;
			add(x,3);fl=1;continue;
		}
		if(cnt3&&cnt1+1<=n/2&&q31.top().w>0){
			int x=q31.top().id;bel[x]=1;ans=ans-a[x][3]+a[x][1];q31.pop();
			cnt3--;cnt1++;
			add(x,1);fl=1;continue;
		}
		if(cnt3&&cnt2+1<=n/2&&q32.top().w>0){
			int x=q32.top().id;bel[x]=2;ans=ans-a[x][3]+a[x][2];q32.pop();
			cnt3--;cnt2++;
			add(x,2);fl=1;continue;
		}
		if(cnt1&&cnt2&&q12.top().w+q21.top().w>0){
			int x=q12.top().id;bel[x]=2;ans=ans-a[x][1]+a[x][2];
			int y=q21.top().id;bel[y]=1;ans=ans-a[y][2]+a[y][1];
			add(x,2);add(y,1);
			fl=1;continue;
		}
		if(cnt2&&cnt3&&q23.top().w+q32.top().w>0){
			int x=q23.top().id;bel[x]=3;ans=ans-a[x][2]+a[x][3];
			int y=q32.top().id;bel[y]=2;ans=ans-a[y][3]+a[y][2];
			add(x,3);add(y,2);
			fl=1;continue;
		}
		if(cnt1&&cnt3&&q13.top().w+q31.top().w>0){
			int x=q13.top().id;bel[x]=3;ans=ans-a[x][1]+a[x][3];
			int y=q31.top().id;bel[y]=1;ans=ans-a[y][3]+a[y][1];
			add(x,3);add(y,1);
			fl=1;continue;
		}
	}while(fl);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		solve();
	}
	return 0;
}

