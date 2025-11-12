#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
#define gc getchar()
void read(int &n){int l=1,num=0;char ch;
while(ch=gc,ch<'0'||ch>'9')if(ch=='-')
l=-1;num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=l*num;return;}

int n,k,a[N],f[N],ma[N],s[N],num[N],tong[2000006];

signed main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		tong[s[i-1]]=i;
		num[i]=tong[k^s[i]];
	}
	for(int i=1;i<=n;i++){if(num[i])f[i]=1+ma[num[i]-1];ma[i]=max(ma[i-1],f[i]);}
	int ans=0;for(int i=1;i<=n;i++)ans=max(ans,f[i]);cout<<ans;return 0;
}

