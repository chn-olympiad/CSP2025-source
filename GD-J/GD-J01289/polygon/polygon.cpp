#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,n,a[5001],ans;
void dfs(long long f,long long k,long long n2,long long sum){
	if(k==n2-1) return (void)(ans+=max((long long)0,lower_bound(a+1,a+1+n,sum)-a-f));
	for(long long i=f;i<=n;i++) dfs(i+1,k+1,n2,sum+a[i]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=3;i<=n;i++) dfs(1,0,i,0);
	cout<<ans;
	return 0;
}
/*A：老师应该不知道我带了两个人格来考试吧
B：应该不知道
A：我们来估一下分吧
B：哦。你有信心AK吗
A：有。
B: 这么强？那你第一题A了吗
A：应该A了嗯对
B：那第二题呢 
A：应该A了因为我是乃龙嗯对
B：那第三题呢
A：应该A了因为囧架架囧囧架嗯对
B：那第四题呢
A：应该A了因为阿帕次阿帕次嗯对
B：哇塞这么强
A：我们都有光明的未来
B：我们都有光明的未来*/

