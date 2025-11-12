#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,m,a[1000010];
pair<int,int> c[1000100];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i].second,c[i].first=i;
	if(n<=10){
		int cnt=0;
		do{
			int tot=0,pre=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0||pre>=c[i].second) pre++;
				else tot++;
			}
			if(tot>=m) cnt++;
		}while(next_permutation(c+1,c+n+1));
		cout<<cnt;
	}
} 
