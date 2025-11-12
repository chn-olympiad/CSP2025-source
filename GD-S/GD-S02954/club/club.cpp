#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
#define pc(a) putchar(a)
#define f(i,a,b,n) for(int i=a;i<=b;i+=n)
#define ms(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair(a,b)
#define _1 first
#define _2 second
#define TT template<typename T> 
using namespace std;
TT T in(){
	T c=0,f=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<3)+(c<<1)+(ch^48);
		ch=gc(); 
	}
	return c*f;
}
TT void out(T x){
	if(x<0) pc('-'),x=-x;
	if(x<10) pc(x^48);
	else out<T>(x/10),pc((x%10)^48);
}
int t,n,a[100005][4],num[4],ans;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qu[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in<int>();
	while(t--){
		f(i,1,3,1) qu[i]=qu[0];
		n=in<int>(),num[1]=num[2]=num[3]=ans=0;
		f(i,1,n,1) f(j,1,3,1) a[i][j]=in<int>();
		f(i,1,n,1){
			int minn;
			if((a[i][1]-a[i][2])*(a[i][1]-a[i][3])<=0) minn=a[i][1];
			else if((a[i][2]-a[i][1])*(a[i][2]-a[i][3])<=0) minn=a[i][2];
			else minn=a[i][3];
			a[i][1]-=minn,a[i][2]-=minn,a[i][3]-=minn;
			ans+=minn;
		}
		f(i,1,n,1){
			int maxs=0,maxnum=0,maxans=-100000;
			f(j,1,3,1){
				if(num[j]<n/2){
					if(maxans<a[i][j]) maxans=a[i][j],maxnum=j,maxs=0;
				}else{
					int x=qu[j].top()._2;
					f(k,1,3,1) if(j!=k) if(a[i][j]+a[x][k]-a[x][j]>maxans) maxans=a[i][j]+a[x][k]-a[x][j],maxnum=j,maxs=k;
				}
			}
			ans+=maxans;
			if(maxs==0) num[maxnum]++,qu[maxnum].push(mp(a[i][maxnum],i));
			else{
				num[maxs]++;
				qu[maxs].push(mp(a[qu[maxnum].top()._2][maxs],qu[maxnum].top()._2));
				qu[maxnum].pop();
				qu[maxnum].push(mp(a[i][maxnum],i));
			}
		}
		out<int>(ans),pc('\n');
	}
	return 0;
}
