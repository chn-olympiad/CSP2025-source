#include<bits/stdc++.h>
using namespace std;
int yasuo(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='b'){
			return i;
		}
		if(s[i]!='a')	return -1;
	}
	return -1;
}
int main(){
	freopen("replace4.in","r",stdin);
	freopen("replace4.out","w",stdout);
	int n,q,a[200001];
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[i]=yasuo(s1)-yasuo(s2);
	}
	for(int i=0;i<q;i++){
		string s1,s2;
		int f=0;
		cin>>s1>>s2;
		int tmp=yasuo(s1)-yasuo(s2);
		for(int j=0;j<n;i++){
			if(a[j]==tmp){
				f++;
			}
		}
		cout<<f<<endl;
	}
}
/*
 * 感觉这replace比T2还简单，至少可以骗分
 * 懒得打A了，直接看B
 * 将一个“特别的”字符串压缩为一个数tmp,表示b在其中的位置
 * 将一个“特别的”变换压缩为一个数x，表示b前移的格数
 * 则由tmp1->tmp2变为求一个数x,使得tmp2-tmp1=x;
 * 有这个x输出1，反之输出0
 * 怎么暴0了？
 * 铛～～我听到了『因果』的回响！
 * 江若雪：你要弄清楚其中的因果关系，因为你考前好好复习了，所以你这次考试会AK。
 * 铛～～我听到了『强运』的回响！
 * 云瑶：欸，口红弹回来了？
 * */