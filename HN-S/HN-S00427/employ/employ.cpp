#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,a=1,m;
	cin>>n>>m;
	if (n==m){
		string s;
		cin>>s;
		if (s.find('0')!=-1){
			cout<<0;
			return 0;
		}
	}
	for (int i=1;i<=n;i++) a=a*i%998244353;
	cout<<a;
	return 0;
}
//不知道该写些什么
//总之，我这把肯定没什么搞头了
//我也算入坑编程这么久，大概有四五年了
//参加3次csp，无功无名
//就连J组的一等奖都是泡影
//我爸要我抓住这次机会，他以后不会让我再参加了
//学习压力大，再搞也搞不了了
//的确啊
//时光荏苒，岁月如梭
//我却只能在比赛中混个脸熟
//啥也不剩了……
//我也真的真的没什么耐心了 
//R.I.P 2025/11/1 
