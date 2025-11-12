#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
using AR=array<int,2>;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	VI num;//用于记录在字符串中出现过的每个数字，值域0~9，不会爆int 
	string s;cin>>s;
	FOR(i,0,(int)s.size())if(s[i]>='0'&&s[i]<='9')num.push_back(s[i]-'0');//一旦判定为数字就放入num 
	sort(begin(num),end(num));//将数字从大到小排序（此处实现为从小到大，输出时逆序输出） 
	for(int i=(int)num.size()-1;i>=0;i--)cout<<num[i];
	return 0;
}
//基本想法：
//1.选的数字越多答案越大
//2.选的数字中，越大的数字放在越前面，答案越大
//把所有的数字记下来，排序再输出即可 
//（会有人写桶排吗？） 
//11-01 08:43:43