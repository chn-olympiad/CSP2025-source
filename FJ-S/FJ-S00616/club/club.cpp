#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
} 
int T,n,s[3],a[N][3],p[N],v[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		s[0]=s[1]=s[2]=0;
		long long ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 0;j<3;j++)a[i][j]=read();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])s[0]++,ans+=a[i][0],p[i]=0;
			else if(a[i][1]>=a[i][2])s[1]++,ans+=a[i][1],p[i]=1;
			else s[2]++,ans+=a[i][2],p[i]=2;
		}
		if(max(max(s[0],s[1]),s[2]) <= n/2){
			printf("%lld\n",ans);
			continue;
		}
		int ff=0;
		if(s[ff]<s[1])ff=1;
		if(s[ff]<s[2])ff=2;
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			if(p[i]==ff){
				int now = 0;
				for(int j = 0;j<3;j++)if(j!=ff)now=max(now,a[i][j]);
				v[++cnt]=a[i][ff]-now;
			}
		}
		sort(v+1,v+cnt+1);
		for(int i = 1;i<=s[ff]-n/2;i++)ans-=v[i];
		printf("%lld\n",ans);
	}
	return 0;
}

