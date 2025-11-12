#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000005
string s;
int a[N],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0){
		cout<<0;
	}else{
	 	for(int i=cnt;i>=1;i--){
			cout<<a[i]; 
		}
	}
	return 0;
} 
//8:34 新建完所有文件
//8:40 写完第T1发现没有打开终端，开始瞪眼
//8:49 发现可以用cpp运行fc.exe 
//8:51 结束T1，测试样例全过，预期：100分 
//8:58 看完T2，想到思路，数学吧~
//9:09 写完T2，题目样例，开始测试测试样例  
//9:16 核对完毕，全过，预期：100分 
//9:17 开始看T3 
//9:17 完蛋，xor异或，看到题目就感觉要完了 
//9:23 跑去写个人信息了
//9:25 回来看题 
//9:31 有点思路 
//9:32 依旧有点思路 
//9:33 没思路了 
//9:34 没思路 
//...
//...
//...
//10:00 可以暴力吧，xor感觉特性挺多的 
//??:?? T4 64分做法 
//11:23 T3 10分做法 
//12:00 100+100+10+64=274 遗憾离场 
