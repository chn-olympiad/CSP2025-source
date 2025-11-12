#include<iostream>
using namespace std;
const int MOD=998244353;
const int N=1e3+5;
int id[N],c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m; cin>>n>>m;
    string s; cin>>s;
    for(int i=1;i<=n;i++) id[i]=s[i-1]-'0';
    for(int i=1;i<=n;i++) cin>>c[i];
    int pd=0;
    for(int i=1;i<=n;i++) if(id[i]==0){pd=1; break;}
    if(pd==0){
		int cnt=0;
	    for(int i=1;i<=n;i++) if(c[i]==0) cnt++;
	    if(cnt>n-m) cout<<0;
	    else{
			long long ans=1;
			for(int i=1;i<=n;i++) ans=(ans*i)%MOD;
			cout<<ans;
		}
	    return 0;	 
	}
	else{
		cout<<0;
	}
    return 0;
}
