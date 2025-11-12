#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int n,a[maxn],k,t[maxn],ans,sum,id=1; 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k); 
	t[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum^=a[i];
		if(t[sum^k]==id){
			id++;
			ans++;
			t[sum]=id;
		}
		else t[sum]=id;
	}
	cout<<ans;
}
/*
退役，不过是终须面对的归宿罢了
归宿，亦不过是终须提交的答案罢了
但答案到底是什么？ 
*/ 
