#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int a[505],n,m,cnt;
string s;
bool flag=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	    cin>>a[i];
	int len=s.size();
	for(int i=0;i<len;i++){
	    if(s[i]=='0') flag=false;
	    else cnt++;
	}
	if(flag==true||m==1){
		long long ans=1;
		for(long long i=2;i<=n;i++)
		    ans=(ans*i)%Mod;
		cout<<ans%Mod<<'\n';
		return 0;
	}
	else if(flag==false&&m==n){
	    cout<<"0\n";
	    return 0;
	}
	else if(m>cnt){
		cout<<"0\n";
		return 0;
	}
    else if(m==cnt){
		long long ans=1;
		for(long long i=2;i<=n;i++)
		    ans=(ans*i)%Mod;
		cout<<ans%Mod<<'\n';
		return 0;
	}	    
	return 0;
}
