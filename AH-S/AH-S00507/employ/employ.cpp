#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=505;
string s;
int n,m,c[N],a[N];
void Brute_force1(){
    int ans=0;
    for(int i=1;i<=n;i++)a[i]=i;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')cnt++;
            else if(cnt>=c[a[i]])cnt++;
        }
        if(n-cnt>=m){
            ans++;
            printf("%lld\n",cnt);
            for(int i=1;i<=n;i++)printf("%lld ",a[i]);
            printf("\n");
        }
    }while(next_permutation(a+1,a+1+n));
    printf("%lld\n",ans);
    return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int sum=0;
    scanf("%lld%lld",&n,&m);
    cin.ignore(),cin>>s,s='0'+s;
    for(int i=1;i<=n;i++)sum+=s[i]-'0';
    for(int i=1;i<=n;i++)scanf("%lld",c+i);
    if(n<=10)Brute_force1();
	return 0;
}
