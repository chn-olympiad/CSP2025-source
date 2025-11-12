#include<bits/stdc++.h>
using namespace std;
/*
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const int N=1000;
int n,m,c[N],unpas[N];
string str;
int main(){
	freopen("employ1.in","r",stdin);//ÑùÀý
	//freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){
		unpas[i]=unpas[i-1];
		if(str[i]-'0'==0)unpas[i]++;
	}
	sort(c+1,c+n+1);

	return 0;
}
*/
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1)cout<<n;
	else{
		int ans=1;
		while(n--){
			ans*=n;
			
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
