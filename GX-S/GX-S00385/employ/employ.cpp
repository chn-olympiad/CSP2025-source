#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=510,mod=998244353;
int n,m,c[maxn],ans,fac[maxn],p[maxn],ifac[maxn],pre[maxn];
string s;
int power(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			ans=ans*a%mod;
			a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void force(){
    for(int i=1;i<=n;i++)
        p[i]=i;
    do{
		int k=0;
        for(int i=1;i<=n;i++)
            if(s[i-1]=='0'||k>=c[p[i]])
                k++;
        if(n-k>=m)
            ans++,ans%=mod;
    }while(next_permutation(p+1,p+1+n));
    cout<<ans;
}
void solveA(){
    cout<<fac[n]%mod;
}
void solveB(int cnt){
	if(m>cnt){
		cout<<0<<"\n";
		return;
	}
	pre[0]=(s[0]=='0');
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]+(s[i]=='0');
}
void solveC(){
	force();
}
void solveD(){
	force();
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    fac[0]=1;
    for(int i=1;i<=n;i++)
        cin>>c[i],fac[i]=fac[i-1]*i%mod;
    bool flag=true;
    int cnt=0;
    for(int i=0;i<n;i++)
        flag&=(s[i]=='1'),cnt+=(s[i]=='1');
    if(flag)
        solveA();
    else if(cnt<=18)
        solveB(cnt);
    else if(m==1)
        solveC();
    else if(m==n)
        solveD();
    else force();
    return 0;
}
// sorry,afo
// i love you,oi
// but i was stupid,i cant ...
