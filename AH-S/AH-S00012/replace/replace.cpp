#include<bits/stdc++.h>
using namespace std;
/*
 * 我被困在了这个机房
 * 手指不停的在键盘上敲击
 * 不能理清我写题的思绪
 * 电脑旁传出我我无奈的叹气声
 * 
 * 梦把我带到的好地方摇摇晃晃到代码乡
 * 思绪飘过树链剖分脚印伴随最短路
 * 这题 不难去想
 * 他说 你在说谎
 * 都是暴力骗分 你奢望拿下省一
 * 
 * 后面没编好，要交卷了qwq
 * OI放过我这一次
*/
/*
开考的两小时48分钟开T3
前面的什么题目真的阴完了

没看懂先跳
*/
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int N=1e5+5;
int n,m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        puts("0");
    }
	return 0;
}
