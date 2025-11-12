#include<bits/stdc++.h>
#define int long long
#define N 5003
#define mod 998244353
using namespace std;

#define gc getchar()
void read(int &n){int l=1,num=0;char ch;
while(ch=gc,ch<'0'||ch>'9')if(ch=='-')
l=-1;num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=l*num;return;}

int n,a[N];
int f[N][N],fs[N][N];

signed main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++)f[i][j]=1;
		for(int j=0;j<=a[n];j++){
			f[i][j]=(f[i][j]+fs[i-1][max((int)0,j-a[i])])%mod;
			fs[i][j]=fs[i-1][j]+f[i][j];
		}
	}
	int ans=0;for(int i=3;i<=n;i++)for(int j=1;j<i;j++)ans=(ans+f[j][a[i]])%mod;
	cout<<ans;
	return 0;
}


