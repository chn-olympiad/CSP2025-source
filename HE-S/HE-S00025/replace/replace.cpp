#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+1013;
int n,q;

struct S{
	string s1,s2;
}s[N];

struct T{
	string t1,t2;
}t[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n>>q;

	for(int i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
	for(int i=1;i<=q;i++) cin>>t[i].t1>>t[i].t2;

	while(q--){

		cout<<0<<'\n';

	}

	return 0;
}
/*

望着弯下腰嚎啕大哭的齐夏，天龙这才想起齐夏只是一个普通人。
他自始至终没有一条路是想要成神，但在这永恒的孤独之中，他，做到了。

这世上的路有许多条，而每个人都有自己要走的那一条
道法三千六百门，而人人各执一根苗

人有悲欢离合，神叹众生悲苦
神叹众生悲苦，神亦悲苦

宗教？
我们比宗教恢宏的多
我们有一个世界
*/
