#include<bits/stdc++.h>
#define int long long
#define _ 100005
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
struct node{
	int num,d1,d2,m1,m2,m3;
	bool operator<(const node &q)const{return d1!=q.d1?d1>q.d1:d2>q.d2;}
}b[_];
int t,n;
int a[_][3],cnt[3];
//set<node>s[3]; 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();for(int i=0;i<3;i++)cnt[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxx=-1,maxid=-1,maxx2=-1,max2id=-1,maxx3=-1,max3id=-1;
			for(int j=0;j<3;j++){
				a[i][j]=read();
				if(a[i][j]>maxx)maxx3=maxx2,max3id=max2id,maxx2=maxx,max2id=maxid,maxx=a[i][j],maxid=j;
				else if(a[i][j]>maxx2)maxx3=maxx2,maxx2=a[i][j],max2id=j;
				else maxx3=a[i][j],max3id=j;
			}
			b[i]=((node){maxx,maxx-maxx2,maxx2-maxx3,maxid,max2id,max3id});
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			if(cnt[b[i].m1]>=(n/2)){
				if(cnt[b[i].m2]>=(n/2)){
					++cnt[b[i].m3],ans+=b[i].num-(b[i].d1+b[i].d2);
				}else{
					++cnt[b[i].m2],ans+=b[i].num-b[i].d1;
				}
			}else{
				++cnt[b[i].m1],ans+=b[i].num;
			}
		}
		printf("%lld\n",ans);
//		set<node>::iterator it;
//		for(int j=0;j<3;j++){
//			if(s[j].size()>(n/2)){
//				
//			}
//		}
//		for(int j=0;j<3;j++){
//			puts("-----");
//			for(it=s[j].begin();it!=s[j].end();it++){
//				printf("%d %d %d\n",it->num,it->d1,it->d2);
//			}	
//		}
		
	}
	return 0;
}
