#include <bits/stdc++.h>
#include <map>

using namespace std;

long long ans=0;
bool vis[100005];
int num[4];
int e[100005][4];



struct t{
	int id,w,b;
	friend bool operator <(const t q,const t w){
		return q.w<w.w;
	}
	friend bool operator >(const t q,const t w){
		return q.w>w.w;
	}
};
priority_queue <t> p;

int n,T;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		priority_queue <t> qwerty;
		swap(p,qwerty);
		memset(vis,0,sizeof(vis));
		cin>>n;
		queue<int> a[4];
		num[1]=0;num[2]=0;num[3]=0;ans=0;
		for(int i=0;i<n;i++){
			t qw,qe,qq;
			qw.id=i;qe.id=i;qq.id=i;
			qw.b=2;qe.b=3;qq.b=1;
			cin>>qq.w>>qw.w>>qe.w;
			p.push(qq);
			p.push(qw);
			p.push(qe);
			e[i][1]=qq.w;e[i][2]=qw.w;e[i][3]=qe.w;
		}
		while(num[1]+num[2]+num[3]<n){
			t m=p.top();
			p.pop();
			if(num[m.b]*2<n && !vis[m.id]){
				ans+=m.w;
				num[m.b]++;
				vis[m.id]=true;
				a[m.b].push(m.id);
			}
			else{
				if(num[m.b]*2==n && !vis[m.id]){
					int tt=-1,f=0,ans2=ans,qwe;
					for(int i=0;i<num[m.b];i++){
						qwe=a[m.b].front();
						a[m.b].pop();
						if(ans-e[qwe][m.b]+e[qwe][(m.b+1)%3+1]+m.w>ans2){
							tt=qwe;
							f=(m.b+1)%3+1;
							ans2=ans-e[qwe][m.b]+e[qwe][(m.b+1)%3+1]+m.w;
						}
						if(ans-e[qwe][m.b]+e[qwe][(m.b)%3+1]+m.w>ans2){
							tt=qwe;
							f=(m.b)%3+1;
							ans2=ans-e[qwe][m.b]+e[qwe][(m.b)%3+1]+m.w;
						}
					}
					if(tt!=-1){
						while(a[m.b].front()!=qwe){
							a[m.b].push(a[m.b].front());a[m.b].pop();
						}
						a[m.b].pop();
						a[f].push(qwe);
						ans=ans2;
						a[m.b].push(m.id);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
