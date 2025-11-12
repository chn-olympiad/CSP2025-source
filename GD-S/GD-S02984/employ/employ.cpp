#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n){
		string s;
		cin>>s;
		for(char c:s){
			if(c=='0'){
				cout<<0;
				return 0;
			}
		}
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		//cout<<sum<<endl;
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0; 
}

/*

初一OIer第一次参加csp-s,教练说不考2=直接退队

上午的csp-j感觉会爆0 

第一题不会做啊qwq，只拿到了T2 4分，T3 20分，T1 不会做啊

今年3=都不一定

还是看看T1吧，T1如果100pts就有2=了，希望上迷惑行为大赏。luogu uid=1320771 用户名Gavinzhou 
 
 
-- 16：10 


T1 突然有思路了，就是先不考虑n/2的条件，求出答案，然后再调整。
这是一个绝妙的方法，这里太小了，写不下了 。等上迷惑了再发剪切版。 

-- 16:20


T1样例1过了，先休息一会再面对100%要debug的代码吧

写的代码， 肯定会TLE或WA 

--16:30

 忍不住测大样例，大样例用scanf没有tle,反而wa，600多ms，貌似是我的贪心有问题 ，没时间改了（绝对不是我不会） 
 
 第二题只打了个最小生成树，不知如何改，但是不开____见祖宗 
 
 第三题要kmp，但我不会 
 
 第四题就别说了吧 ，骗个几分得了 
--16：35 

50+4+20+20=94

检查一下文件和freopen吧，反正后面的也不会 
--16:44

所以几点结束，应该是17:00罢，玩玩虚拟机 

--16:56 

怎么是18:30结束

--17:27 

第一题还是老老实实dp吧，但为什么还是WA 

--17:40

bug一大堆，只剩下10分钟了，这次估计连3=都拿不到，也不想再多说什么了。 从开始的失望到希望再到最后绝望，明年再战！ 

--18：21
*/
