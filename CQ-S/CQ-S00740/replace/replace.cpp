//the code is from chenjh
#include<bits/stdc++.h>
#define MAXL 5000005
#define MAXN 200002
using namespace std;
typedef unsigned long long ULL; 
constexpr ULL b1=1549,b2=3049,p2=1594127239;
int n,q;
ULL bn1[MAXL],bn2[MAXL];
string s1[MAXN],s2[MAXN],t1,t2;
struct HS1{
	vector<ULL> hs;
	void init(const string&s){
		int len=s.length();
		hs.resize(len+1);
		hs[0]=0;
		for(int i=1;i<=len;i++) hs[i]=hs[i-1]*b1+s[i-1];
	}
	ULL ask(const int l,const int r){return hs[r]-hs[l-1]*bn1[r-l+1];}
}h11[MAXN],h21[MAXN],t11,t21;
struct HS2{
	vector<ULL> hs;
	void init(const string&s){
		int len=s.length();
		hs.resize(len+1);
		hs[0]=0;
		for(int i=1;i<=len;i++) hs[i]=(hs[i-1]*b2+s[i-1])%p2;
	}
	ULL ask(const int l,const int r){return (hs[r]-hs[l-1]*bn2[r-l+1]%p2+p2)%p2;}
}h12[MAXN],h22[MAXN],t12,t22;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	for(int i=*bn1=*bn2=1;i<MAXL;i++)
		bn1[i]=bn1[i-1]*b1,bn2[i]=bn2[i-1]*b2%p2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	sort(s1+1,s1+n+1,[](const string&x,const string&y){return x.size()<y.size();});
	sort(s2+1,s2+n+1,[](const string&x,const string&y){return x.size()<y.size();});
	for(int i=1;i<=n;i++)
		h11[i].init(s1[i]),h12[i].init(s1[i]),
		h21[i].init(s2[i]),h22[i].init(s2[i]);
	while(q--){
		cin>>t1>>t2;
		t11.init(t1),t12.init(t1);
		t21.init(t2),t22.init(t2);
		int e=t1.length(),l=0,r=e-1;
		for(;l<e&&t1[l]==t2[l];l++);
		for(;r>=0&&t1[r]==t2[r];--r);
		ULL ans=0;
		for(int i=lower_bound(s1+1,s1+n+1,r-l+1,[](const string&x,const int y){return (int)x.length()<y;})-s1;i<=n&&(int)s1[i].length()<=e;i++)
//			if((int)s1[i].length()>=r-l+1)
			{
				int se=s1[i].length();
				for(int j=max(1,r-se+2),mj=min(l+1,e-se+1);j<=mj;j++)
					ans+=h11[i].ask(1,se)==t11.ask(j,j+se-1)&&h12[i].ask(1,se)==t12.ask(j,j+se-1)&&
						h21[i].ask(1,se)==t21.ask(j,j+se-1)&&h22[i].ask(1,se)==t22.ask(j,j+se-1);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
//mt19937 mtrd(20090318);
//int rd(const int l,const int r){return uniform_int_distribution<int>(l,r)(mtrd);}
//bool isp(const int x){
//	if(x<=1) return 0;
//	for(int i=2;1ll*i*i<=x;i++)if(!(x%i)) return 0;
//	return 1;
//}
//	int x;
//	do x=rd(1e9+4e8,1e9+6e8);while(!isp(x));
//	printf("%d\n",x);
	


Change:



Idea:

字符串问题。

看空间限制像是要建字典树。

答案怎么一串 0，这是要不可以总司令吗。

感觉有可能根号分治。

只能替换一次吗？

那这个问题是不是很好解决了。

好像也不是很好解决。

一个串的替换方案数量是平方级别的。 

求出最长公共前缀和后缀。 

修改的左端点必须要在最长公共前缀之前，修改右端点的位置必须要在最长公共后缀之后。

且前面的部分和后面的部分必须一一对应相等。

在所有的 s 串中暴力的寻找 t 不同的部分，预处理一下哈希，可以做到 O(L1q)，这样可以获得 50 分。 

Command:

g++ replace.cpp -o replace -O2 -std=c++14 -Wall -Wextra -Wshadow -static
g++ replace.cpp -o replace -O2 -std=c++14 -Wall -Wextra -Wshadow -fsanitize=address,undefined,signed-integer-overflow -g

copy .\data\replace\replace1.in replace.in /Y
copy .\data\replace\replace1.ans replace.ans /Y
.\replace
fc replace.out replace.ans

copy .\data\replace\replace2.in replace.in /Y
copy .\data\replace\replace2.ans replace.ans /Y
.\replace
fc replace.out replace.ans

copy .\data\replace\replace3.in replace.in /Y
copy .\data\replace\replace3.ans replace.ans /Y
.\replace
fc replace.out replace.ans

copy .\data\replace\replace4.in replace.in /Y
copy .\data\replace\replace4.ans replace.ans /Y
.\replace
fc replace.out replace.ans

cp ../data/replace/replace1.in replace.in
cp ../data/replace/replace1.ans replace.ans
time ./replace
diff replace.out replace.ans -BZ

cp ../data/replace/replace2.in replace.in
cp ../data/replace/replace2.ans replace.ans
time ./replace
diff replace.out replace.ans -BZ

cp ../data/replace/replace3.in replace.in
cp ../data/replace/replace3.ans replace.ans
time ./replace
diff replace.out replace.ans -BZ

cp ../data/replace/replace4.in replace.in
cp ../data/replace/replace4.ans replace.ans
time ./replace
diff replace.out replace.ans -BZ


*/

