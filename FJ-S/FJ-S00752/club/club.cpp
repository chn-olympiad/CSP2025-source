#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int T,ans=0,n,a[100005][4],sum[4],Ma[100005],ma[100005];
priority_queue<P,vector<P>,greater<P> > q[4];
void init(){
	memset(sum,0,sizeof(sum));
	ans=0;
	for(int i=1;i<=3;i++){
		while(!q[i].empty()){
			q[i].pop();
		}
	}
}
int read(){
	int f=1,ans=0;
	char c;
	c=getchar();
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10+(c-'0');
		c=getchar();
	}
	return ans*f;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		init();
		n=read();
		for(int i=1;i<=n;i++){
			int Max=-1,maxx=-1,cnt=0,id=-1,idd=-1,iddd=-1;
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(Max<a[i][j]){
					Max=a[i][j];
					id=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(a[i][j]==Max) cnt++;
				else{
					if(maxx<a[i][j]) maxx=a[i][j],idd=j;
				}
			}
			for(int j=1;j<=3;j++) if(a[i][j]!=Max&&a[i][j]!=maxx) iddd=j;
			Ma[i]=Max,ma[i]=maxx;
			if(cnt>1) ans+=a[i][id];
			else{
				if(q[id].size()==n/2){
					if(q[id].top().first<Max-maxx){
						sum[id]=sum[id]-Ma[q[id].top().second]+ma[q[id].top().second];
						q[id].pop();
						sum[id]+=Max;
						q[id].push({Max-maxx,i});
					}
					else{
						if(iddd==-1) ans+=maxx;
						else{
							q[idd].push({maxx-a[i][iddd],i}),sum[idd]+=ma[i];
						}
					}
				}
				else q[id].push({Max-maxx,i}),sum[id]+=Max;
			}
		}
		for(int i=1;i<=3;i++) ans+=sum[i];
		printf("%d\n",ans);
	}
}
