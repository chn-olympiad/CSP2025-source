#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vec vector<int>
#define int long long
#define M 998244353
#define pi pair<int,int>
void in(int &x){
	x=0;int f=1;char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,n,m,k,x,y,c[100005];
char s[100005];
int f[2][505][505],ans;
void add(int &x,int y){x=(x+y)%M;}
void sub(int &x,int y){x=(x-y+M)%M;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	in(n);in(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)in(x),c[x]++;
	for(int i=n;i>=0;i--)c[i]+=c[i+1];
	int w=0;for(int i=1;i<=n;i++)if(s[i]=='0')w++;
    for(int i=w;i<=n;i++)f[0][0][i]=1;
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=i-1;j++){
    		for(int k=0;k<=n-i+1;k++){
    			int val=f[(i-1)&1][j][k];
    			if(!val)continue;
    			f[(i-1)&1][j][k]=0;
    			if(s[i]=='0'){
    				if(k)add(f[i&1][j+1][k-1],val*k);
    			}
    			else{
    				int u=n-i-k;
    				if(c[j+1]>=u)add(f[i&1][j][k],val*(c[j+1]-u));
    				if(k)add(f[i&1][j+1][k-1],val*k);
    				if(c[j+1]>=u)sub(f[i&1][j+1][k],val*(c[j+1]-u));
    			}
    		}
    	}
    }
    for(int i=0;i<=n-m;i++)add(ans,f[n&1][i][0]);
    printf("%lld\n",ans);
}