#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5+5;
LL n,k,a[N],pre[N],cnt,l,now;
void solve1(){
	for(LL i=1;i<=n;i++){
		LL ned=(k^pre[i]);
		for(LL j=i-1;j>=l;j--){
			if(pre[j]==ned){
				cnt++;
				l=i;
				break;
			}
		}
	}
	cout<<cnt;
}
void solve2(){
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		cout<<cnt;
	}else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			now^=a[i];
			if(now==k){
				cnt++;
				now=0;
			}
		}
		cout<<cnt;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}
	if(n<=2e3) solve1();
	else solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
