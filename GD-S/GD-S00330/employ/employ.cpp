#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1;
int s[505],d[505],a[505],p[505];
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		if(s1[i-1]=='0')s[i]=s[i-1]+1;
		else s[i]=s[i-1];
		d[i]=s1[i-1]-'0';
	}
	//for(int i=1;i<=n;i++)cout<<d[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		long long ans=0;
		do{
			int t=0,g_up=0;
			for(int i=1;i<=n;i++){
				if((a[p[i]]>g_up)&&(d[i]==1))t++;
				else g_up++;
			}
			if(t>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	else cout<<0;
	return 0;
} 
