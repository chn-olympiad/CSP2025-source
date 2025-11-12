#include<bits/stdc++.h>
using namespace std;
long long T,n,p,ans,cnt,f[100005],s[5];
struct node{long long x,id;}d[100005][5];
bool cmp(node a,node b){return a.x>b.x;}
long long read(long long s=0,bool f=0,char c=0){
	while(c<'0'||c>'9')c=getchar(),f|=(c=='-');
	while(c>='0'&&c<='9')s=s*10+c-'0',c=getchar();
	return f?-s:s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read(),s[1]=s[2]=s[3]=p=cnt=ans=0;
		for(int i=1;i<=n;i++){
			d[i][1].x=read(),d[i][2].x=read(),d[i][3].x=read(),d[i][1].id=1,d[i][2].id=2,d[i][3].id=3;
			sort(d[i]+1,d[i]+4,cmp),s[d[i][1].id]++,ans+=d[i][1].x;
		}
		if(s[1]>s[2]&&s[1]>s[3])p=1;
		else if(s[2]>s[3])p=2;
		else p=3;
		if(s[p]<=n/2)cout<<ans<<endl;
		else{
			for(int i=1;i<=n;i++)
				if(d[i][1].id==p)
					cnt++,f[cnt]=d[i][1].x-d[i][2].x;
			sort(f+1,f+cnt+1);
			for(int i=1;i<=s[p]-n/2;i++)ans-=f[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}

