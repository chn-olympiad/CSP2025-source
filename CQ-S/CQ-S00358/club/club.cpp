#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=210;
struct Node{
	int a,b,c;
}s[100010];
bool cmp1(Node t1,Node t2){
	return t1.b-t1.a>t2.b-t2.a;
}
bool cmp2(Node t1,Node t2){
	return t1.a>t2.a;
}
int f[N][N][N];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		int n;
		cin>>n;
		if(n<=200){
			for(int i=1;i<=n;i++){
				cin>>s[i].a>>s[i].b>>s[i].c;
				for(int j=0;j<=i;j++){
					for(int k=0;k<=i;k++){
						if(j>0&&j+k<=i)f[j][k][i-j-k]=f[j-1][k][i-j-k]+s[i].a;
						if(k>0&&j+k<=i)f[j][k][i-j-k]=max(f[j][k][i-j-k],f[j][k-1][i-j-k]+s[i].b);
						if(i-j-k>0)f[j][k][i-j-k]=max(f[j][k][i-j-k],f[j][k][i-j-k-1]+s[i].c);
		//				cout<<j<<" "<<k<<" "<<i-j-k<<":"<<f[j][k][i-j-k]<<endl;
					}
				}
		//		cout<<endl;
			}
			int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(i+j>=n/2)ans=max(ans,f[i][j][n-i-j]);
				}
			}
			cout<<ans<<"\n";
		}
		else {
			bool fl1=1,fl2=1;
			for(int i=1;i<=n;i++){
				cin>>s[i].a>>s[i].b>>s[i].c;
				if(s[i].b!=0&&s[i].c!=0)fl1=0;
				if(s[i].c!=0)fl2=0;
			}
			int ans=0;
			if(fl1){
				sort(s+1,s+1+n,cmp2);
				int ans=0;
				for(int i=1;i<=n/2;i++)ans+=s[i].a;
				cout<<ans<<"\n";
			}
			else if(fl2){
				sort(s+1,s+1+n,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=s[i].b;
				}
				for(int i=n/2+1;i<=n;i++){
					ans+=s[i].a;
				}
				cout<<ans<<"\n";
			}
			else {
				for(int i=1;i<=n;i++){
					int maxn=max(max(s[i].a,s[i].b),s[i].c);
					if(s[i].a==maxn)ans+=s[i].a;
					else if(s[i].b==maxn)ans+=s[i].b;
					else ans+=s[i].c;
				}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
