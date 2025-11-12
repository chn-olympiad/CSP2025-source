#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+20;
inline int read(){
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return f*k;
}
int n;
struct mouse_king{
	int a,b,c;
	int k,id,kd;
}f[N],tmp[N];
inline bool cmp(mouse_king x,mouse_king y){
	return x.k>y.k;
}
inline bool cmp1(mouse_king x,mouse_king y){
	return x.a>y.a;
}
inline bool cmp2(mouse_king x,mouse_king y){
	return x.b>y.b;
}
inline bool cmp3(mouse_king x,mouse_king y){
	return x.c>y.c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int ans=0;
		int cnt[4]={};
		n=read();
		int flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			f[i].a=read();
			f[i].b=read();
			f[i].c=read();
			if(f[i].c!=0) flag1=flag2=0;
			if(f[i].b!=0) flag1=0;
			if(f[i].a>=f[i].b&&f[i].a>=f[i].c){
				f[i].k=f[i].a,f[i].id=1;
			}else if(f[i].b>=f[i].a&&f[i].b>=f[i].c){
				f[i].k=f[i].b,f[i].id=2;
			}else if(f[i].c>=f[i].a&&f[i].c>=f[i].b){
				f[i].k=f[i].c,f[i].id=3;
			}
		}
		if(n<=2){
			int maxn=0;
			maxn=max(maxn,f[1].a+f[2].b);
			maxn=max(maxn,f[1].a+f[2].c);
			maxn=max(maxn,f[1].b+f[2].a);
			maxn=max(maxn,f[1].b+f[2].c);
			maxn=max(maxn,f[1].c+f[2].a);
			maxn=max(maxn,f[1].c+f[2].b);
			cout<<maxn<<endl;
			continue;
		}else if(flag1){
			sort(f+1,f+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=f[i].a;
			}
			cout<<ans<<endl;
			continue;
		}else if(flag2){
			sort(f+1,f+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(cnt[1]>=n/2){
					for(int j=i;j<=n;j++){
						ans+=f[i].b;
					}
					break;
				}
				if(cnt[2]>=n/2){
					for(int j=i;j<=n;j++){
						ans+=f[i].a;
					}
					break;
				}
				cnt[f[i].id]++;
				ans+=f[i].k;
			}
			cout<<ans<<endl;
		}else if(n<=10){
			int res=0;
			for(int i=0;i<=(1<<n)-1;i++){
				res=0;
				int maxn=0;
				int num=0;
				for(int k=0;k<n;k++){
					if((i>>k)&1){
						num++;
						res+=f[i].a;
					}
				}
				if(num>n/2) continue;
				int res1=0;
				for(int j=0;j<=(1<<n)-1;j++){
					res1=0;
					if(i&j) continue;
					num=0;
					for(int k=0;k<n;k++){
						if((j>>k)&1){
							res1+=f[i].b;
							num++;
						}
					}
					if(num>n/2) continue;
					int g=i|j;
					num=0;
					for(int k=0;k<n;k++){
						if((g>>k)&1!=1){
							num++;
							res1+=f[i].c;
						}
					}
					if(num>n/2) continue;
					maxn=max(maxn,res1);
				}
				ans=max(ans,maxn+res);
			}
			cout<<ans<<endl;
		}else{
			int num=0;
			sort(f+1,f+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[f[i].id]<(n/2)){
				ans+=f[i].k;
				cnt[f[i].id]++;
			}else{
				if(f[i].id==1){
					tmp[++num].a=0;
					tmp[num].b=f[i].b;
					tmp[num].c=f[i].c;
					if(f[i].b>=f[i].c){
						tmp[num].kd=3;
						tmp[num].id=2;
						tmp[num].k=f[i].b;
					}else{
						tmp[num].kd=2;
						tmp[num].id=3;
						tmp[num].k=f[i].c;
					}
				}else if(f[i].id==2){
					tmp[++num].a=f[i].a;
					tmp[num].b=0;
					tmp[num].c=f[i].c;
					if(f[i].a>=f[i].c){
						tmp[num].kd=3;
						tmp[num].id=1;
						tmp[num].k=f[i].a;
					}else{
						tmp[num].kd=1;
						tmp[num].id=3;
						tmp[num].k=f[i].c;
					}
				}else if(f[i].id==3){
					tmp[++num].a=f[i].a;
					tmp[num].b=f[i].b;
					tmp[num].c=0;
					if(f[i].a>=f[i].b){
						tmp[num].kd=2;
						tmp[num].id=1;
						tmp[num].k=f[i].a;
					}else{
						tmp[num].kd=1;
						tmp[num].id=2;
						tmp[num].k=f[i].b;
					}
				}
			}
		}
		sort(tmp+1,tmp+num+1,cmp);
		for(int i=1;i<=num;i++){
			if(cnt[tmp[i].id]<(n/2)){
				ans+=tmp[i].k;
				cnt[tmp[i].id]++;
			}else{
				if(tmp[i].kd==1) ans+=tmp[i].a,cnt[1]++;
				else if(tmp[i].kd==2) ans+=tmp[i].b,cnt[2]++;
				else if(tmp[i].kd==3) ans+=tmp[i].c,cnt[3]++;
			}
		}
		cout<<ans<<'\n';
		}
	}
	
	
	
	
	
	return 0;
}
