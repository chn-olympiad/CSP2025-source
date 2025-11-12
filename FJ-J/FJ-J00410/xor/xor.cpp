#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5*1e5+5;
ull n,k,a[N],cnt,lk;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lk = lk^a[i];
		if(lk==k){
			cnt++;
			lk = 0;
		}
	}
	cout<<cnt;
	return 0;
}
