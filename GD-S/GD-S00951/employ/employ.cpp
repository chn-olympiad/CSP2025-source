#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string s;
int n,m,ar[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	f(i,1,n)cin>>ar[i];
	sort(ar+1,ar+n+1);
	int cnt=1,c=0;
	f(i,1,n){
		if(s[i]=='1'){
			while(i-1-c<=ar[cnt]&&cnt<=n)cnt++;
			if(cnt<=n)c++;
		}
	}cout<<pow(cnt,c)
}
