#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],j=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]>='0'&&s[i]<='9')a[j++]=s[i]-'0';
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++)cout<<a[i];
}
/*
代码太短注释来凑 

崩铁UID忘了原神早退了084也没记住1999更不想记
（都老演员[指参赛次数]了怎么还这么不靠谱)
上次没选上这次试试

好像能整的活前人都整了(悲）
 
 
离考试结束还有1个小时
现在能干什么
一年没学纯裸考来的
J初赛考78
S初赛考成78
 
要是我这一年学一点绝对没这么拉
第三题怎么做不知道 先把01的分骗了
第四题知道怎么做但是忘了怎么写
干脆dfs暴力拿n<=20的+max[n,i=1]a(i)=1的得了
喝 竟然有48~60分
那不管了
开摆


bro回家打硫化碳去力(喜)
啊嘿嘿嘿嘿 

 
*/