#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
string s;
int a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a;
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353ll;
	}
	cout<<ans;
	return 0;
}
/*
我不知道该说些什么，反正打完这场应该就AFO了
初三还是太忙了，不再像去年那样天天练了
当了一年半的OIer感觉挺有感触的，不知道明年还能不能重来
本来是不想AFO的，但快中考了，凭我这个OI成绩也去不到哪里，没办法
刚开始当兴趣学，后来不知不觉就成了OIer
开始的时光还是很快乐的
但现在机房里的同学大概都比我强了，渐渐压力开始大起来
我曾经想过要不要退役，但那时觉得时间还早，还能冲一冲，但现在不行了
我的文化课成绩还算过的去吧，学校在市上排第三，学校将近1000人排在30多位，勉强还是能上市里最好的高中
我文采不好，所以写不出什么很好的东西，大家就当乐子看吧
刚上完厕所回来，透过小窗看见金黄的落日和被太阳镶上金边的云，觉得很美，却不知怎么说
“ 答：作者通过描写落日十分美好的景象，反衬出作者内心的悲伤，一句”不知怎么说“体现出作者即将与OI分别的不舍与无奈之情。”（雾）
欢乐的时光总是短暂的，马上要结束了
总是，还是要感谢我的父母，老师和一起学OI的同学们
如果你是正在读这篇文章的OIer或是整理代码大赏工作者，我也向你们道一声辛苦了
或许我们还会再见

#include<iostream>
using namespace std;
int main(){
cout<<"Hello,World!";
return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
printf("Bye,World!");
return 0;
}

2025 11.1 16:26:20
*/