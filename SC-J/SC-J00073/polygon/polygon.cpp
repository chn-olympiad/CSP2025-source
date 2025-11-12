//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
#include<bits/stdc++.h>
//I love CCF very much
using namespace std;
//I love CCF very much
const int kkksc03=998244353;
//I love CCF very much
int N;
//I love CCF very much
int a[5005];
//I love CCF very much
void solve1(){
//I love CCF very much
	long long ans=0;
//I love CCF very much
	for(int i=N-2;i>=1;i--){
//I love CCF very much
		long long sum=1;
//I love CCF very much
		for(int j=N;j>=i;j--){
//I love CCF very much
			sum*=j;
//I love CCF very much
			sum%=kkksc03;
//I love CCF very much
		}
//I love CCF very much
		ans+=sum;
//I love CCF very much
	}
//I love CCF very much
	cout<<ans;
//I love CCF very much
	return ;
//I love CCF very much
}
//I love CCF very much
void solve2(){
//I love CCF very much
	sort(a+1,a+N+1);
//I love CCF very much
	int x=a[1],y=a[2],z=a[3];
//I love CCF very much
	if(x+y>z)cout<<1;
//I love CCF very much
	else cout<<0;
//I love CCF very much
	return ;
//I love CCF very much
}
//I love CCF very much
void solve3(){
//I love CCF very much
	//Idk我不会 
//I love CCF very much
}
//I love CCF very much
int main(){
//I love CCF very much
	freopen("polygon.in","r",stdin);
//I love CCF very much
	freopen("polygon.out","w",stdout);
//I love CCF very much
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//I love CCF very much
	cin>>N;
//I love CCF very much
	if(N<3){
//I love CCF very much
		cout<<0;
//I love CCF very much
		return 0;
//I love CCF very much
	}
//I love CCF very much
	bool f1=1;
//I love CCF very much
	for(int i=1;i<=N;i++){
//I love CCF very much
		cin>>a[i];
//I love CCF very much
		if(a[i]!=1)f1=0;
//I love CCF very much
	}
//I love CCF very much
	if(f1)solve1();
//I love CCF very much
	else if(N==3)solve2();
//I love CCF very much
	else solve3();
//I love CCF very much
	return 0;
//I love CCF very much
}
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much

/*
CSP-J 坐标SC 
现在是10：48：50，开始写游记
T1 很简单，处理字符串之后排序就好了
T2 也很简单， 因为数据范围很小，10*10，直接两个for就行了，注意判断单双列
T3 有点难度，数据很大，我的 O(n^2) 的算法只能过12个点，希望CCF的数据弱一点，让我多过几个点
T4 很难，子集枚举忘记怎么打了，只写了n<=3和ai==1的情况
预估分数 100+100+60+36==296pts
应该是1=
我真强

10:58
右边的小孩哥没带纸就想上厕所，我给了他一包纸 

11:01
吃了两根火腿肠

11:02
想上厕所，发现小孩哥把我纸用完了

11:05
不知道干什么，就把T3的常数优化了一下，希望能多过1个点 

11:11
优化后惊奇地发现200000的数据只跑了0.2秒，这样的话1秒就可以跑1e6左右，可以A掉T3!!!!!!!!!!
预估分数 100+100+100+36=336
1= 和 5√应该是稳了 

11:20
在代码里加入了一个名为kkksc03的变量 

11:30
想把T2的题面抄在准考证上，但最终还是放弃了
不能上厕所了！！！

11:32
玩了一会儿3D画图

11:42 
玩了一会儿计算器

11:43
吃了一个面(man)包 

11:45
复制了很多个"I love CCF very much" 

11:49
被监考老师发现我复制了很多个"I love CCF very much"，老师笑了

11:50
我不行了，“代码长度4000字节”

11:51
增加了亿些换行

11:52
交代码了，游记到此为止吧 

希望进洛谷CSP迷惑行为大赏
洛谷名 heyihong2012 
Uid ? 忘了
 
*/
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much
//I love CCF very much











































































































































































































































































































































































































































































































































































































































































































































































































































