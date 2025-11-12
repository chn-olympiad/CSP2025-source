#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[505];
string s;
long long p,ans,o,lo,np;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	ans=1;
	int t=1;
	int f=1;
	for (int i=0;i<s.size();i++)if (s[i]=='0')f=0;
	if (f){
		ans=1;
		for (int i=n;i>(n-m);i--){
	//	cout<<i<<" ";
			ans=(ans*i)%998244353;
		}
	}else{
		for (int i=1;i<s.size();i++){
			if (s[i]=='1'){
				int sum=0;
				for (int j=t;j<=n;j++){
					if (c[i]>=p){
						if (t==1)t=j;
						sum++;
					}
				}
				//cout<<ans<<" ";
				if (n-sum>=o+p)ans=ans*sum%998244353;
				else ans=ans*(sum-(o+p-n+sum))%998244353;
				//np=0;
				o++;
			}else{
				//np++;
				p++;
			}
		}
	}
	cout<<ans;
	return 0;
}
