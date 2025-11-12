#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,mod=1e9+7;
int a[20];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(char ch:s) if(isdigit(ch)) a[ch-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=a[i];j++) cout<<i;
	return 0;
}
/*
WARNING: All my comments after the code are in UTF-8 format. Please do not use Dev-C++ to view.
大家好，我是去年的 GD-J03182，今年回来啦！
今年，我要蓝钩！
题外话：关注 @Shellchen 谢谢喵！
----------------------------------------非常不优雅的分割线----------------------------------------
100pts
预估红
*/ 
