//我承诺遵守中国计算机学会相关规定
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[1470495];
ll head=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	ll has0=s.length();
	for(int i=0; i<s.length(); ++i){
		if(isdigit(s[i])){
			a[head++]=(s[i]-'0');
			if(a[head-1]==0) has0--;
		}
		else has0--;
	}
	if(has0==0){
		cout<<0; return 0;
	}
	sort(a,a+head);
	for(int i=head-1; i>=0; --i){
		cout<<a[i];
	}
	return 0;
}












//有中文那就好了，先来诈骗一波
//freopen(".in","r",stdout)
//feropen(".out,"w",stdin)
//freeopen(".in","r","stdin")

/*
8:27 好问题：Linux虚拟机在哪里
8:29 get ready. 
8:31 压缩包密码:#Shang4Shan3Ruo6Shui4 
     上善若水？
8:36 建好所有文件&文件夹 
8:50 4个样例都没有问题，下一题 
目测<入门>至<普及-> 
*/
//100+0+0+0=100, no prize 
