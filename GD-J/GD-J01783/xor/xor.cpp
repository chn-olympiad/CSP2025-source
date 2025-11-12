#include<bits/stdc++.h>
using namespace std;
#define int long long 
int last=0,a[500005];
int n,k,cnt;
void s(int index){//从index到last开始逆序寻找
	int add=a[index];
	for(int i=index-1;i>=last+1;i--){
		add^=a[i];
		if(add==k){
			cnt++;
			last=index;
			return;
		}
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	//&有假就假  ^都真就假 |有真就真、
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k){cnt++;last=i;continue;}
		if(a[i]==0) continue;
		s(i);
	}
	cout<<cnt;
	return 0;
}

