#include<bits/stdc++.h>
using namespace std;

const int M=998244353;
int n,m,c[505],a[505];
string s;
long long ans;

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	
	for(int i=1;i<=n;i++) a[i]=i;
	
	do{
		int rs=0;
		for(int i=1;i<=n;i++){
			if(rs>=c[a[i]]){
				rs++;
				continue;
			}
			if(s[i-1]=='0') rs++;
		}
		
		if(n-rs>=m) ans=(ans+1)%M;
	}while(next_permutation(a+1,a+1+n));
	
	cout<<ans;
	
	return 0;
}
