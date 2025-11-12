#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,c[1001],a[1001],x=1,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n<=10){
		for(int i=1;i<=n;i++){
			x*=i;
			cin>>c[i];
			a[i]=i;
		} 
		while(x--){
			int l=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0'||l>=c[a[i]]){
					l++;
				}
			}
			if(n-l>=m){
				ans++;
			}
			next_permutation(a+1,a+n+1);
		}
		cout<<ans;
	}
	return 0;
} 
