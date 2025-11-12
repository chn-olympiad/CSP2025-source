#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e4+5;
int T,n,ans;
int f[N][4];
pair<int,int> a[N];
bool bq,cq;
int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') putchar('-');
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs(int dep,int ai,int bi,int ci,int cnt){
	if(ai>n/2||bi>n/2||ci>n/2) return;
	if(dep>n){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1) ai++;
		if(i==2) bi++;
		if(i==3) ci++;
		cnt+=f[dep][i];
		dfs(dep+1,ai,bi,ci,cnt);
		if(i==1) ai--;
		if(i==2) bi--;
		if(i==3) ci--;
		cnt-=f[dep][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		memset(f,0,sizeof(f));
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			f[i][1]=read(),f[i][2]=read(),f[i][3]=read();
			a[i]=make_pair(f[i][1],f[i][2]);
			if(f[i][2]!=0) bq=true;
			if(f[i][3]!=0) cq=true;
		}
		if(!cq){
			sort(a+1,a+n+1);
			if(!bq){
				for(int i=n;i>n/2;i--) ans+=a[i].first;
			}else{
				int ai=0,bi=0;
				for(int i=1;i<=n;i++){
					if((a[i].first>a[i].second&&ai<n/2)||bi>=n/2){
						ai++;
						ans+=a[i].first;
					}else ans+=a[i].first,bi++;
				}
			}
			write(ans),puts("");
			continue;
		}
		dfs(1,0,0,0,0);
		write(ans),puts("");
	}
	return 0;
}
