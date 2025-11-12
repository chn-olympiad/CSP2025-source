#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
long long t,n,a[N][5],ans,k,p,e[5],o;
int dx[5]={0,2,1,1};
int dy[5]={0,3,3,2};
struct node{
	long long k;
	bool operator <(const node &x)const
	{
		return x.k<k;
	}
}w;
priority_queue<node> q;
struct hhh{
	long long id;
}b[N];
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
long long cdz(long long x){
	if(a[x][dx[b[x].id]]<a[x][dy[b[x].id]]){
		return dy[b[x].id];
	}
	else{
		return dx[b[x].id];
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		ans=0;
		for(int i=1;i<=3;i++){
			e[i]=0;
		}
		for(int i=1;i<=n;i++){
			p=-1;k=1;
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(a[i][j]>p)
				{
					p=a[i][j];
					k=j;
				}
			}
			b[i].id=k;
			e[b[i].id]++;
		}
		for(int i=1;i<=3;i++){
			if(e[i]>n/2)o=i;
		}
		for(int i=1;i<=n;i++){
			if(b[i].id==o){
				if(q.size()==n/2)
				{
					w=q.top();
					if(w.k<a[i][b[i].id])
					{
						ans=ans-(w.k)+a[i][b[i].id];
						q.pop();
						w.k=a[i][b[i].id]-max(a[i][dx[b[i].id]],a[i][dy[b[i].id]]);
						q.push(w);
					}
					else
					{
						ans=ans+max(a[i][dx[b[i].id]],a[i][dy[b[i].id]]);
					}
				}
				else
				{
					w.k=a[i][b[i].id]-max(a[i][dx[b[i].id]],a[i][dy[b[i].id]]);
					q.push(w);
					ans+=a[i][b[i].id];
				}
			}
			else{
				ans+=a[i][b[i].id];
			}
		}
		while(!q.empty()){
			q.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
