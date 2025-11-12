#include <bits/stdc++.h>
using namespace std;
inline int read(){
	char c;
	do{
		c=getchar();
	}while(c<'0'||'9'<c);
	int sum=0;
	do{
		sum=10*sum+c-'0';
		c=getchar();
	}while('0'<=c&&c<='9');
	return sum;
}
typedef long long ll;
const int N=110000;
int n;
int a[N][3],b[N];
void solve(){
	n=read();
	for(int i=1;i<=n;i++)
		for(int k=0;k<3;k++)
			a[i][k]=read();
	ll ans=0;
	int cnt[3]={0,0,0};
	for(int i=1;i<=n;i++){
		b[i]=0;
		for(int k=1;k<3;k++)
			if(a[i][k]>a[i][b[i]])
				b[i]=k;
		ans+=a[i][b[i]];
		cnt[b[i]]++;
	}
	int x=-1;
	for(int k=0;k<3;k++)
		if(cnt[k]>n/2)
			x=k;
	if(x!=-1){
		vector <int> p;
		for(int i=1;i<=n;i++){
			if(b[i]==x){
				int res=0;
				for(int k=0;k<3;k++)
					if(k!=x)
						res=max(res,a[i][k]);
				p.push_back(a[i][b[i]]-res);
			}
		}
		sort(p.begin(),p.end());
		for(int i=0;i<cnt[x]-n/2;i++)
			ans-=p[i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
		solve(); 
	return 0;
}
