#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[501],let[501],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)let[i]=i;
	bool f=1;
	while(f){
		int k=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				k++;
				continue;
			}
			else {
				if(k>=a[let[i]]){
					k++;
					continue;
				}
				else sum++;
			}
		}
		if(sum>=m){
			ans++;
		}
		f=next_permutation(let+1,let+1+n);
	}
	cout<<ans%998244253;
	return 0;
}//dyx i love you!!!dyx i love you!!!dyx i love you!!!dyx i love you!!!dyx i love you!!!dyx i love you!!!
// my name is liangcha_crush_ly,please give me a chance to take part in "haohuodashang" TV programme because it's my dream
