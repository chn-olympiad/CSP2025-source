/*
1.for循环是否写对
2.是否把==写成=
3.倒序遍历是否i--
4.是否溢出，是否开long long
5.数组是否越界，特别注意a[i-k]
6.是否freopen写对
7.n*m是否<=m
8.是否包含：left,right,next,prev,y0,yn,j0,j1,jn等变量名
9.是否删debug语句
//*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')t+=s[i];
	sort(t.begin(),t.end(),cmp);
	cout<<t;
	return 0;
}
