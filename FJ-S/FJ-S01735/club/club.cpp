#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
const int N=1e5+10;

int T,n;
int a[N],b[N],c[N];

vector<int> ss1,ss2,ss3,tmp;

signed main(){
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	T=read();
	while(T--){
		ss1.clear(),ss2.clear(),ss3.clear(),tmp.clear();		
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read(),b[i]=read(),c[i]=read();
			if(a[i]>=b[i]&&a[i]>=c[i])ans+=a[i],ss1.push_back(i);
			else if(b[i]>=a[i]&&b[i]>=c[i])ans+=b[i],ss2.push_back(i);
			else ans+=c[i],ss3.push_back(i);
		}
		
		if(ss1.size()>n/2){
			int res=ss1.size()-n/2;
			for(int i=0;i<ss1.size();i++){
				int u=ss1[i];
				tmp.push_back(max(b[u],c[u])-a[u]);
			}
			sort(tmp.begin(),tmp.end());
			for(int i=1;i<=res;i++)ans+=tmp[tmp.size()-i];
		}
		
		else if(ss2.size()>n/2){
			int res=ss2.size()-n/2;
			for(int i=0;i<ss2.size();i++){
				int u=ss2[i];
				tmp.push_back(max(a[u],c[u])-b[u]);
			}
			sort(tmp.begin(),tmp.end());
			for(int i=1;i<=res;i++)ans+=tmp[tmp.size()-i];
		}
		
		else if(ss3.size()>n/2){
			int res=ss3.size()-n/2;
			for(int i=0;i<ss3.size();i++){
				int u=ss3[i];
				tmp.push_back(max(b[u],a[u])-c[u]);
			}
			sort(tmp.begin(),tmp.end());
			for(int i=1;i<=res;i++)ans+=tmp[tmp.size()-i];
		}
		write(ans);
		putchar('\n');
	}
	
	return 0;
}