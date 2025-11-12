#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long ans,mod=998244353;
int n,m,c[N],f[N];
string s;
void work1(){
    ans=1;
    for(int i=0;i<n;i++)
        if(s[i]=='0'||c[i]==0){printf("0");return ;}
    for(int i=1;i<=n;i++)
	    ans=ans*i%mod;
    printf("%lld",ans);
}
void dfs(int i,int num){
	if(n-num<m) return ;
    if(i==n){
	    if(n-num>=m) ans++;
	    return ;
	}
	for(int j=0;j<n;j++){
        if(f[j]) continue;
        f[j]=1;
        if(s[i]=='1'&&num<c[j]) dfs(i+1,num);     
        else dfs(i+1,num+1);
        f[j]=0;
    } 
}
void work2(){
    dfs(0,0);
    printf("%lld",ans);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s; 
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    sort(c,c+n);
    if(m==n) work1();
    else if(n<=10) work2();
    return 0;
}
