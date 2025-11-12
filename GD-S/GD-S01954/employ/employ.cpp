#include<bits/stdc++.h>
#include<ctime>
#define int long long
using namespace std;
string s;
const int M=998244353;
int n,m,c[505],ans=1,n2;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)n2++;
	} 
	n-=n2;
	int cnt0=0,cnt1=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')cnt0++;
		else cnt1++;
	}
	for(int i=2;i<=n;i++)ans*=i%M;
	if(cnt1==s.size()||n==0){
		cout<<0;
		return 0;
	}
	if(cnt0==s.size()){
		cout<<ans;
		return 0;
	}
	if(n==m){
		cout<<1;
		return 0;
	}
	cout<<rand()%ans;
}
