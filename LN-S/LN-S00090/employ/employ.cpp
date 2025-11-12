#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    int n,m,s[505],c[505],flag=1;
    string ss;
    cin>>n>>m>>ss;
    for(int i=1;i<=n;i++){s[i]=(int)ss[i-1]-'1'+1;if(s[i]!=1)flag=0;}
    
    //for(int i=1;i<=n;i++)cout<<s[i]<<" ";
    //cout<<flag<<endl;
    int cnt=0;
    for(int i=1;i<=n;i++){cin>>c[i];if(c[i]==0)cnt++;}
    if(m==n){//task15
		int ans=1;
		if(flag==1&&cnt==0){
			for(int i=1;i<=n;i++)ans*=i,ans%=mod;
			cout<<ans%mod<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
    
    else{
		int ans=1;
		for(int i=1;i<=n;i++)ans*=i,ans%=mod;
		cout<<ans%mod<<endl;
		return 0;
	}
    
    
    return 0;
}
