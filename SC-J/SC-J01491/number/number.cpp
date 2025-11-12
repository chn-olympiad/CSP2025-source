#include<bits/stdc++.h>
using namespace std;
namespace solve{
	inline int read(){
		int x=0,f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
		return x*f;
	}
	vector<int>v;
	string s;
	int solve(){
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		cin>>s;
		for(char &ch:s)
			if(isdigit(ch))
				v.emplace_back(ch-'0');
		sort(v.begin(),v.end(),greater<int>());
		for(auto i:v)cout<<i;
		cout<<endl;
		return 0;
	}
}
int main(){return solve::solve();}
/*
This is maybe the last year I sitting here for CSP-J, maybe not?
My code in T3 is worstly O(n^2), but the best O(n).
So it's difficult to predict my final score.
It can be 300 to 340.Too low, right?

Btw, I love @Arrtan_73 (not gay)
I love @Arrtan_73
I love @Arrtan_73
I love @Arrtan_73
I love @Arrtan_73
I love @Arrtan_73
I love @Arrtan_73
I love @Arrtan_73
I love @Arrtan_73
I love @Arrtan_73

Everyone who see pls send "I love @Arrtan_73" to him, before 2025/12/31.
pls pls pls pls pls pls pls ,and pls keep it a secret, even though he ask you.
                                                		2025/11/1 11:30 in CDQZ

[11:32]Shall I keep thinking on T3? What if i worked it out? Let's see...
[11:34]I want to pray for the testcase is not created by rng...
[11:48]You can even see "getchar_unlocked()" in my code...
		and all the functions have "inline" ...
[11:56]Sadly, I failed.
*/
//to ensure you can find this:
//------------don't read the word below---------------
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//foropen
//fropen
//Genshin impact
/*
Microsoft Windows [版本 10.0.22000.318]
(c) Microsoft Corporation。保留所有权利。

D:\work>fc number1.out number1.ans
正在比较文件 number1.out 和 NUMBER1.ANS
FC: 找不到差异


D:\work>fc number2.out number2.ans
正在比较文件 number2.out 和 NUMBER2.ANS
FC: 找不到差异


D:\work>fc number3.out number3.ans
正在比较文件 number3.out 和 NUMBER3.ANS
FC: 找不到差异


D:\work>fc number4.out number4.ans
正在比较文件 number4.out 和 NUMBER4.ANS
FC: 找不到差异


D:\work>
*/