#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define putc(c) putchar(c)
inline int read(){
	int x=0,t=0;
	char c=gc();
	while(c<'0'||c>'9') t|=c=='-',c=gc();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
	return t?-x:x;
}
inline void write(int x){
	if(x<0) putc('-'),x=-x;
	if(x>9) write(x/10);
	putc(x%10+'0');
}
#define mpr make_pair
#define pii pair<int,int>
#define fir first
#define sec second
const int N=1e5+10;
int T,n,a[N][3],ct[3],tp[N];
int main(){
//	system("fc club1.out club1.ans /n");
//	system("fc club2.out club2.ans /n");
//	system("fc club3.out club3.ans /n");
//	system("fc club4.out club4.ans /n");
//	system("fc club5.out club5.ans /n");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			int mx=0,mxp=-1;
			for(int j=0;j<3;j++)
				a[i][j]=read(),(a[i][j]>mx?(mx=a[i][j],mxp=j):0);
			tp[i]=mxp,ct[mxp]++,ans+=mx;
		}
		int p=-1;
		for(int i=0;i<3;i++)
			if(ct[i]*2>n)
				p=i;
		if(p!=-1){
//			cerr<<"!!!"<<endl;
			vector<int>vc;
			for(int i=1;i<=n;i++){
				if(tp[i]!=p) continue;
				int mn=1e9;
				for(int j=0;j<3;j++)
					if(j!=p)
						mn=min(mn,a[i][p]-a[i][j]);
				vc.push_back(mn);
			}
			sort(vc.begin(),vc.end());
			vc.resize(ct[p]-n/2);
			for(auto tp:vc) ans-=tp;
		}
		write(ans),putc('\n');
		for(int i=0;i<3;i++)
			ct[i]=0;
	}
}
