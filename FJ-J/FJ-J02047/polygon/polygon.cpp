#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,a[10005],ans,tmp;
int sel[10005];
bool vis[10005];
int calc=0;
int t2;
int dfs(int idx,int k,int l){
	t2=0;
	if(idx==0){
		for(register int i=1;i<=k;i++){
			t2+=sel[i];
		}
		if(t2>2*sel[1]){
			calc++;
			return 1; 
		}
		else{
			return 0;
		} 
	}
	
	for(int i=l;i<=n;i++){
		if(!vis[i]){
			sel[idx]=a[i];
			vis[i]=1;
			dfs(idx-1,k,i+1);
			calc%=mod;
			vis[i]=0;
		}
	}
	return calc;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>20){
		for(int i=3;i<=n;i++){
			tmp=1;
			for(int j=n;j>n-i;j--){
				tmp*=j; tmp%=mod;tmp/=n-j+1;
			}
			ans+=tmp;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		for(int i=3;i<=n;i++){
			dfs(i,i,1);ans+=calc;calc=0;
			ans%=mod;
		}
		cout<<ans;
	}
	cout<<endl;
	return 0;
}
/*
idk whats the purpose of participating this thing
360 for nothing
CNY Searching Project--Junior Group (?
i mean why
expensive bruh
and no use
i mean
like it's only some use if you got 1= in S
cuz u get to go to noip
and j is like useless
just a certificate and nothing
even reviewing and studying at home is better
(though i might spend the time in playing mc) 
like wasting 360 rmb and 3.5 hours of time in studying (mc)
xd
rp+=inf;
tho it is my last competition in OI
gotta go back to study whk
boring
very boring
estimated 100+100+50+64=314
tired
AFO.
bruh.
soon.
......
ok xd theres actully another thing called CSP-S in the afternoon
*/
