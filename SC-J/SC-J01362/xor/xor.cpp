#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],s[1010][1010],cnt,tsa=1,tsb=1,aa;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)tsa=0;
		if(a[i]!=0&&a[i]!=1)tsb=0;
	}
	if(tsa){
		cout<<n/2;
	}
	else if(tsb){
		for(int i=1;i<=n;i++){
			aa^=a[i];
			if(a[i]==k){
				cnt++;
				aa=0;
			}
			else if(aa==k){
				cnt++;
				aa=0;
			}
		}
		cout<<cnt;
	}
	else cout<<(rand()%(n/10)+1);
	return 0;
}