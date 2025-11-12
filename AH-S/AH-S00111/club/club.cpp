#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int t;
int a[100010][4];
int b[100010];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	int n;
	while(t>0){
		t--;
		n=read();
		int f1=0;
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(a[i][2]) f1=1;
		}
		if(!f1){
			int ans=0;
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		if(n==2){
			int ans=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						ans=max(ans,a[1][i]+a[2][j]);
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
